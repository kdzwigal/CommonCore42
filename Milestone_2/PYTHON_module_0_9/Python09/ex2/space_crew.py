from enum import Enum
from datetime import datetime
from typing_extensions import Self
try:
    from pydantic import BaseModel, Field, model_validator, ValidationError
except ImportError:
    print("Pydantic is not installed ---->>>  pip install pydantic")

class Rank(str, Enum):
    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewMember(BaseModel):

    member_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=2, max_length=50)
    rank: Rank
    age: int = Field(..., ge=18, le=80)
    specialization: str = Field(..., min_length=3, max_length=30)
    years_experience: int = Field(..., ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):

    mission_id: str = Field(..., min_length=5, max_length=15)
    mission_name: str = Field(..., min_length=3, max_length=100)
    destination: str = Field(..., min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(..., ge=1, le=3650)
    crew: list[CrewMember] = Field(..., min_length=1, max_length=12)
    mission_status: str = "planned"
    budget_millions: float = Field(..., ge=1.0, le=10000.0)

    @model_validator(mode='after')
    def validate_mission_rules(self) -> Self:

        if not self.mission_id.startswith("M"):
            raise ValueError('Mission ID must start with "M"')

        has_leader = any(
            member.rank in [Rank.COMMANDER, Rank.CAPTAIN] for member in
            self.crew)
        if not has_leader:
            raise ValueError(
                "Mission must have at least one Commander or Captain")

        if self.duration_days > 365:
            experienced_count = sum(
                1 for member in self.crew if member.years_experience >= 5)
            print(experienced_count)
            if experienced_count / len(self.crew) < 0.5:
                raise ValueError("Long missions (> 365 days) need at "
                                 "least 50% experienced crew (5+ years)")

        if not all(member.is_active for member in self.crew):
            raise ValueError("All crew members must be active")

        return self


def main() -> None:
    print("Space Mission Crew Validation")
    print("=========================================")

    valid_data = """  
    {
    "mission_id": "M2024_TITAN",
    "mission_name": "Solar Observatory Research Mission",
    "destination": "Solar Observatory",
    "launch_date": "2024-03-30T00:00:00",
    "duration_days": 451,
    "crew": [
      {
        "member_id": "CM001",
        "name": "Sarah Williams",
        "rank": "captain",
        "age": 43,
        "specialization": "Mission Command",
        "years_experience": 19,
        "is_active": true
      },
      {
        "member_id": "CM002",
        "name": "James Hernandez",
        "rank": "captain",
        "age": 43,
        "specialization": "Pilot",
        "years_experience": 30,
        "is_active": true
      },
      {
        "member_id": "CM003",
        "name": "Anna Jones",
        "rank": "cadet",
        "age": 35,
        "specialization": "Communications",
        "years_experience": 15,
        "is_active": true
      },
      {
        "member_id": "CM004",
        "name": "David Smith",
        "rank": "commander",
        "age": 27,
        "specialization": "Security",
        "years_experience": 15,
        "is_active": true
      },
      {
        "member_id": "CM005",
        "name": "Maria Jones",
        "rank": "cadet",
        "age": 55,
        "specialization": "Research",
        "years_experience": 30,
        "is_active": true
      }
    ],
    "mission_status": "planned",
    "budget_millions": 2208.1
    }"""
    try:
        valid_mission = SpaceMission.model_validate_json(valid_data)

        print("Valid mission created:")
        print(f"Mission: {valid_mission.mission_name}")
        print(f"ID: {valid_mission.mission_id}")
        print(f"Destination: {valid_mission.destination}")
        print(f"Duration: {valid_mission.duration_days} days")
        print(f"Budget: ${valid_mission.budget_millions}M")
        print(f"Crew size: {len(valid_mission.crew)}")
        print("Crew members:")
        for member in valid_mission.crew:
            print(
                f"- {member.name} ({member.rank.value}) - {member.specialization}")


    except ValidationError as e:
        print("Expected validation error:")
        for error in e.errors():
            msg = error.get("msg", "").replace("Value error, ", "")
            print(msg)

    print("=========================================")

    invalid_data = """{
    "mission_id": "AM2024_MARS",
    "mission_name": "Jupiter Orbit Colony Mission",
    "destination": "Jupiter Orbit",
    "launch_date": "2024-10-01T00:00:00",
    "duration_days": 1065,
    "crew": [
      {
        "member_id": "CM011",
        "name": "Emma Brown",
        "rank": "commander",
        "age": 49,
        "specialization": "Mission Command",
        "years_experience": 5,
        "is_active": true
      },
      {
        "member_id": "CM012",
        "name": "John Hernandez",
        "rank": "lieutenant",
        "age": 36,
        "specialization": "Science Officer",
        "years_experience": 4,
        "is_active": true
      },
      {
        "member_id": "CM013",
        "name": "Sofia Rodriguez",
        "rank": "lieutenant",
        "age": 29,
        "specialization": "Life Support",
        "years_experience": 2,
        "is_active": true
      },
      {
        "member_id": "CM014",
        "name": "Sofia Lopez",
        "rank": "lieutenant",
        "age": 44,
        "specialization": "Systems Analysis",
        "years_experience": 4,
        "is_active": true
      }
    ],
    "mission_status": "planned",
    "budget_millions": 4626.0
    }"""

    try:
        invalid_mission = SpaceMission.model_validate_json(invalid_data)

        print(f"Invalid mission somehow created: {invalid_mission.mission_id}")

    except ValidationError as e:
        print("Expected validation error:")
        for error in e.errors():
            msg = error.get("msg", "").replace("Value error, ", "")
            print(msg)


if __name__ == "__main__":
    main()