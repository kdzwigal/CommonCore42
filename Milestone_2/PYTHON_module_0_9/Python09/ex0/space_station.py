from datetime import datetime
from pydantic import BaseModel, Field, ValidationError


class SpaceStation(BaseModel):
    """Pydantic model representing a space station with validation rules."""

    station_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=1, max_length=50)
    crew_size: int = Field(..., ge=1, le=20)
    power_level: float = Field(..., ge=0.0, le=100.0)
    oxygen_level: float = Field(..., ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = True
    notes: str | None = Field(default=None, max_length=200)


def main() -> None:

    json_string_ok = """
    {
        "station_id": "QCH189",
        "name": "Deep Space Observatory",
        "crew_size": 3,
        "power_level": 70.8,
        "oxygen_level": 88.1,
        "last_maintenance": "2023-08-24T00:00:00",
        "is_operational": false,
        "notes": "System diagnostics required"
    }"""

    print("Space Station Data Validation")
    print("========================================")

    # 1. Tworzenie prawidłowej instancji (Valid station)
    try:
        valid_station = SpaceStation.model_validate_json(json_string_ok)

        print("Valid station created:")
        print(f"ID: {valid_station.station_id}")
        print(f"Name: {valid_station.name}")
        print(f"Crew: {valid_station.crew_size} people")
        print(f"Power: {valid_station.power_level}%")
        print(f"Oxygen: {valid_station.oxygen_level}%")

        status = "Operational" if valid_station.is_operational else "Offline"
        print(f"Status: {status}")

    except ValidationError as e:
        print(f"Expected validation error: \n {e}")

    print("========================================")

    json_string_ko = """
    {
        "station_id": "ISS877",
        "name": "Mars Orbital Platform",
        "crew_size": 30,
        "power_level": 179.7,
        "oxygen_level": 187.2,
        "last_maintenance": "2023-10-06T00:00:00",
        "is_operational": false,
        "notes": "System diagnostics required"
    }
    """

    # 2. Próba utworzenia nieprawidłowej instancji (Invalid station)
    try:
        # Przypisujemy nieprawidłową wartość m.in. do crew_size (> 20)
        invalid_station = SpaceStation.model_validate_json(json_string_ko)

        # Ta linijka nie powinna się nigdy wykonać z powodu błędu walidacji
        print(f"Invalid station somehow created: {invalid_station.station_id}")

    except ValidationError as e:
        print("Expected validation error:")
        # Wyłapujemy tylko komunikat z błędem dla zmiennej 'crew_size',
        # aby dopasować to idealnie do oczekiwanego wyniku (Expected Output)
        for error in e.errors():
            if "crew_size" in error.get("loc", []):
                print(error.get("msg"))
            else:
                print(error.get("msg"))


if __name__ == "__main__":
    main()
