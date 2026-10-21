from .dark_validator import validate_ingredients


def dark_spell_allowed_ingredients() -> list[str]:
    return ["bats", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str) -> str:
    valid = validate_ingredients(ingredients)
    if valid.endswith(" - VALID"):
        return f"Spell recorded: {spell_name} ({valid})"
    return f"Spell rejected: {spell_name} ({valid})"
