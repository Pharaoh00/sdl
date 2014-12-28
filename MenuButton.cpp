#include "MenuButton.h"
#include "InputHandler.h"
#include "Vector2D.h"

MenuButton::MenuButton(const LoaderParams *pParams, void (*callback)()) :
SDLGameObject(pParams), m_callback(callback) {
  m_currentFrame = MOUSE_OUT; // start at frame 0
}

void MenuButton::draw() {
  SDLGameObject::draw();
}

void MenuButton::update() {
  Vector2D *pMousePos = TheInputHandler::Instance()->getMousePosition();

  if (pMousePos->getX() < (m_position.getX()+m_width)
  && pMousePos->getX() > m_position.getX()
  && pMousePos->getY() < (m_position.getY()+m_height)
  && pMousePos->getY() > m_position.getY()) {
    if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased) {
      m_currentFrame = CLICKED;
      m_callback();
      // ensure that we release the mouse button before doing the callback again.
      m_bReleased = false;
    } else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
      m_bReleased = true;
      m_currentFrame = MOUSE_OVER;
    }
  } else {
    m_currentFrame = MOUSE_OUT;
  }
}

void MenuButton::clean() {
  SDLGameObject::clean();
}
