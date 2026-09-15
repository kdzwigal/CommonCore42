import typing

from ex1 import HealingCreatureFactory, TransformCreatureFactory


def invoke_action(obj: typing.Any, method_name: str) -> str:

    try:
        method = getattr(obj, method_name)
        result = method()
        if not isinstance(result, str):
            raise TypeError(f"Method '{method_name}' didn't return a string")
        return result
    except AttributeError:
        raise AttributeError(f"Object does not have capability: {method_name}")
    except TypeError as e:
        raise TypeError(f"Invalid call for '{method_name}': {e}")


def test_healing() -> None:

    print("\nTesting Creature with healing capability")
    factory = HealingCreatureFactory()

    try:
        base = factory.create_base()
        print(" base:")
        print(invoke_action(base, "describe"))
        print(invoke_action(base, "attack"))
        print(invoke_action(base, "heal"))

        evolved = factory.create_evolved()
        print(" evolved:")
        print(invoke_action(evolved, "describe"))
        print(invoke_action(evolved, "attack"))
        print(invoke_action(evolved, "heal"))

    except Exception as e:
        print(f"Error testing healing creatures {e}")


def test_transform() -> None:

    print("\nTesting Creature with transform capability")
    factory = TransformCreatureFactory()

    try:
        base = factory.create_base()
        print(" base:")
        print(invoke_action(base, "describe"))
        print(invoke_action(base, "attack"))
        print(invoke_action(base, "transform"))
        print(invoke_action(base, "attack"))
        print(invoke_action(base, "revert"))

        evolved = factory.create_evolved()
        print(" evolved:")
        print(invoke_action(evolved, "describe"))
        print(invoke_action(evolved, "attack"))
        print(invoke_action(evolved, "transform"))
        print(invoke_action(evolved, "attack"))
        print(invoke_action(evolved, "revert"))

    except Exception as e:
        print(f"Error testing transform creatures: {e}")


def main() -> None:
    test_healing()
    test_transform()


if __name__ == "__main__":
    main()
