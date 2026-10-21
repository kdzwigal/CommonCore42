import alchemy
from elements import create_fire
from ..potions import strength_potion


def lead_to_gold() -> str:
    return (f"Recipe transmuting Lead to Gold: brew "
            f"’{alchemy.create_air()}’ and ’{strength_potion()}’ "
            f"mixed with ’{create_fire()}'")
