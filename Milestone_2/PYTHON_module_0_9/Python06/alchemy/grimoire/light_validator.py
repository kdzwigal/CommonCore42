from . import light_spellbook as ls


def validate_ingredients(ingredients: str) -> str:
    allowed = ls.light_spell_allowed_ingredients()
    lower_ingredients = ingredients.lower()
    for item in allowed:
        if item not in lower_ingredients:
            return f"{ingredients} - INVALID"
    return f"{ingredients} - VALID"
