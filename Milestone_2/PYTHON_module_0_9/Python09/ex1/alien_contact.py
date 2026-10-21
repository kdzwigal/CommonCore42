from enum import Enum
from datetime import datetime
try:
    from pydantic import BaseModel, Field, model_validator, ValidationError
except ImportError:
    print("Pydantic is not installed ---> pip install pydantic")


class ContactType(str, Enum):
    RADIO = "radio"
    VISUAL = "visual"
    PHYSICAL = "physical"
    TELEPATHIC = "telepathic"


class AlienContact(BaseModel):

    contact_id: str = Field(..., min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(..., min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(..., ge=0.0, le=10.0)
    duration_minutes: int = Field(..., ge=1, le=1440)
    witness_count: int = Field(..., ge=1, le=100)
    message_received: str | None = Field(default=None, max_length=500)
    is_verified: bool = False

    @model_validator(mode='after')
    def validate_business_rules(self) -> 'AlienContact':

        if not self.contact_id.startswith("AC"):
            raise ValueError('Contact ID must start with "AC"')

        if self.contact_type == ContactType.PHYSICAL and not self.is_verified:
            raise ValueError("Physical contact reports must be verified")

        if (self.contact_type == ContactType.TELEPATHIC and
                self.witness_count < 3):
            raise ValueError(
                "Telepathic contact requires at least 3 witnesses")

        if self.signal_strength > 7.0 and not self.message_received:
            raise ValueError(
                "Strong signals (> 7.0) should include received messages")

        return self


def main() -> None:
    print("Alien Contact Log Validation")
    print("======================================")

    valid_data = """
    {
        "contact_id": "AC_2024_006",
        "timestamp": "2024-02-02T00:00:00",
        "location": "Area 51, Nevada",
        "contact_type": "radio",
        "signal_strength": 2.7,
        "duration_minutes": 20,
        "witness_count": 14,
        "message_received": null,
        "is_verified": false
    }
    """

    try:
        valid_contact = AlienContact.model_validate_json(valid_data)

        print("Valid contact report:")
        print(f"ID: {valid_contact.contact_id}")
        print(f"Type: {valid_contact.contact_type.value}")
        print(f"Location: {valid_contact.location}")
        print(f"Signal: {valid_contact.signal_strength}/10")
        print(f"Duration: {valid_contact.duration_minutes} minutes")
        print(f"Witnesses: {valid_contact.witness_count}")
        print(f"Message: '{valid_contact.message_received}'")

    except ValidationError as e:
        print(f"Unexpected validation error: {e}")

    print("======================================")

    invalid_data = """
    {
        "contact_id": "AC_2024_005",
        "timestamp": "2024-09-10T00:00:00",
        "location": "SETI Institute, California",
        "contact_type": "telepathic",
        "signal_strength": 6.4,
        "duration_minutes": 134,
        "witness_count": 2,
        "message_received": "Warning about solar flare activity",
        "is_verified": false
    }
    """

    try:
        invalid_contact = AlienContact.model_validate_json(invalid_data)

        print(f"Invalid contact somehow created: {invalid_contact.contact_id}")

    except ValidationError as e:
        print("Expected validation error:")
        for error in e.errors():
            msg = error.get("msg", "")
            clean_msg = msg.replace("Value error, ", "")
            print(clean_msg)


if __name__ == "__main__":
    main()
