#include "scenes/StartMenu.hpp"
#include <iostream>
#include <raylib.h>
#include <string>
#include <vector>

// Special
StartMenu::StartMenu() {}; // Constructor

// Fetches
std::vector<MenuItem> StartMenu::getMenuItems() { return menuItems; };
int StartMenu::getSelectedItem() { return selectedItem; };
bool StartMenu::getStartedGame() { return startedGame; };

// Actions

void StartMenu::draw() {
  for (auto &item : menuItems) {
    Color col = item.hovering ? LIGHTGRAY : DARKGRAY;
    DrawRectangleRec(item.rect, col);
    DrawText(item.text.c_str(), item.rect.x + 20, item.rect.y + 10, 20, WHITE);
  }
}

std::string StartMenu::update() {

  menuItems.at(selectedItem).hovering = false;

  if (IsKeyPressed(KEY_DOWN)) {
    selectedItem++;
  };

  if (IsKeyPressed(KEY_UP)) {
    selectedItem--;
  };

  if (selectedItem < 0) {
    selectedItem = menuItems.size() - 1;
  };

  if (selectedItem >= menuItems.size()) {
    selectedItem = 0;
  };

  menuItems.at(selectedItem).hovering = true;

  if (IsKeyPressed(KEY_SPACE)) {
    if (menuItems[selectedItem].text == "Start Game") {
      startedGame = true;
    };
    return (menuItems[selectedItem].text);
  }
  return "None";
};
