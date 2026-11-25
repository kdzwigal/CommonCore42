from enum import Enum

from Pydantic import BaseModel, Field

class Zone(str, Enum):
    normal = "normal"
    blocked = "blocked"
    restricted = "restricted"
    priority = "priority"

class Color(str, Enum):
    red = "red"
    green = "green"
    blue = "blue"
    yellow = "yellow"
    purple = "purple"
    gray = "gray"
    none = "none"

class Type(str, Enum):
    hub = "hub"
    start_hub = "start_hub"
    end_hub = "end_hub"

class Hub(BaseModel):

    type: Type = Field(default=Type.hub)
    name: str = Field()
    x: int = Field(ge=0)
    y: int = Field(ge=0)
    zone: Zone = Field(default=Zone.normal)
    color: Color = Field(default=Color.none)
    max_drones: int = Field(default=1, ge=1)

class Connection(BaseModel):
    from_hub: Hub = Field()
    to_hub: Hub = Field()
    max_link_capacity: int = Field(default=1, ge=1)

class FlyIn:

    grid: list[list[list[Hub]]] = [[[]]]
