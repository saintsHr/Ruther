#include "ruther/input/input.hpp"

#include <raylib.h>

namespace Ruther::Input {

bool isKeyPressed(Key key){
    bool state = ::IsKeyPressed(static_cast<int>(key));

    return state;
}

bool isKeyReleased(Key key){
    bool state = ::IsKeyReleased(static_cast<int>(key));

    return state;
}

bool isKeyDown(Key key){
    bool state = ::IsKeyDown(static_cast<int>(key));

    return state;
}

bool isKeyUp(Key key){
    bool state = ::IsKeyUp(static_cast<int>(key));

    return state;
}

bool isMouseButtonPressed(MouseButton button) {
    bool state = ::IsMouseButtonPressed(static_cast<int>(button));

    return state;
}

bool isMouseButtonReleased(MouseButton button) {
    bool state = ::IsMouseButtonReleased(static_cast<int>(button));

    return state;
}

bool isMouseButtonDown(MouseButton button) {
    bool state = ::IsMouseButtonDown(static_cast<int>(button));

    return state;
}

bool isMouseButtonUp(MouseButton button) {
    bool state = ::IsMouseButtonUp(static_cast<int>(button));

    return state;
}

Vec2 getMousePosition() {
    Vector2 position = ::GetMousePosition();

    return {
        static_cast<double>(position.x),
        static_cast<double>(position.y)
    };
}

Vec2 getMouseDelta() {
    Vector2 delta = ::GetMouseDelta();

    return {
        static_cast<double>(delta.x),
        static_cast<double>(delta.y)
    };
}

double getMouseScroll() {
    float scroll = ::GetMouseWheelMove();

    return static_cast<double>(scroll);
}

}
