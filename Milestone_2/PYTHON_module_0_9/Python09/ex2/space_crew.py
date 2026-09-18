from enum import Enum
from datetime import datetime
from typing_extensions import Self
from pydantic import BaseModel, Field, model_validator, ValidationError


class Rank(str, Enum):
    """Enumeration for crew member ranks."""
    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewMember(BaseModel):
    """Model representing an individual crew member."""

    member_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=2, max_length=50)
    rank: Rank
    age: int = Field(..., ge=18, le=80)
    specialization: str = Field(..., min_length=3, max_length=30)
    years_experience: int = Field(..., ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    """Model representing a space mission with a nested list of crew members."""

    mission_id: str = Field(..., min_length=5, max_length=15)
    mission_name: str = Field(..., min_length=3, max_length=100)
    destination: str = Field(..., min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(..., ge=1, le=3650)

    # W Pydantic v2 min_length i max_length działają również dla struktury list!
    crew: list[CrewMember] = Field(..., min_length=1, max_length=12)
    mission_status: str = "planned"
    budget_millions: float = Field(..., ge=1.0, le=10000.0)

    @model_validator(mode='after')
    def validate_mission_rules(self) -> Self:
        """
        Validates safety requirements and crew dependencies for the mission.
        """
        # Rule 1: Mission ID must start with "M"
        if not self.mission_id.startswith("M"):
            raise ValueError('Mission ID must start with "M"')

        # Rule 2: Must have at least one Commander or Captain
        has_leader = any(
            member.rank in [Rank.COMMANDER, Rank.CAPTAIN] for member in
            self.crew)
        if not has_leader:
            raise ValueError(
                "Mission must have at least one Commander or Captain")

        # Rule 3: Long missions (> 365 days) need 50% experienced crew (5+ years)
        if self.duration_days > 365:
            experienced_count = sum(
                1 for member in self.crew if member.years_experience >= 5)
            if experienced_count / len(self.crew) < 0.5:
                raise ValueError(
                    "Long missions (> 365 days) need at least 50% experienced crew (5+ years)")

        # Rule 4: All crew members must be active
        if not all(member.is_active for member in self.crew):
            raise ValueError("All crew members must be active")

        return self


def main() -> None:
    print("Space Mission Crew Validation")
    print("=========================================")

    # Przygotowanie instancji członków załogi
    sarah = CrewMember(
        member_id="C001", name="Sarah Connor", rank=Rank.COMMANDER,
        age=45, specialization="Mission Command", years_experience=20
    )
    john = CrewMember(
        member_id="C002", name="John Smith", rank=Rank.LIEUTENANT,
        age=35, specialization="Navigation", years_experience=10
    )
    alice = CrewMember(
        member_id="C003", name="Alice Johnson", rank=Rank.OFFICER,
        age=28, specialization="Engineering", years_experience=6
    )

    # 1. Tworzenie prawidłowej misji
    try:
        valid_mission = SpaceMission(
            mission_id="M2024_MARS",
            mission_name="Mars Colony Establishment",
            destination="Mars",
            launch_date="2024-10-01T12:00:00Z",
            duration_days=900,
            crew=[sarah, john, alice],
            budget_millions=2500.0
        )

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
        print(f"Unexpected validation error: {e}")

    print("=========================================")

    # 2. Próba utworzenia misji z błędem walidacji na poziomie głównym (brak lidera)
    try:
        invalid_mission = SpaceMission(
            mission_id="M2024_MOON",
            mission_name="Lunar Base Resupply",
            destination="Moon",
            launch_date="2024-11-01T08:00:00Z",
            duration_days=14,
            crew=[john, alice],  # Brakuje Commander'a lub Captain'a
            budget_millions=500.0
        )
        print(f"Invalid mission created: {invalid_mission.mission_id}")
    except ValidationError as e:
        print("Expected validation error:")
        for error in e.errors():
            msg = error.get("msg", "").replace("Value error, ", "")
            print(msg)


if __name__ == "__main__":
    main()