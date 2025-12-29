#pragma once
#include <raylib.h>
#include <string>
#include <vector>

struct MenuItem {
  std::string text;
  Rectangle rect;
  bool hovering;
};

class StartMenu {
private:
  std::vector<MenuItem> menuItems = {{"Start Game", {300, 200, 200, 50}, true},
                                     {"Settings", {300, 260, 200, 50}, false},
                                     {"Exit", {300, 320, 200, 50}, false}};
  int selectedItem = 0;
  bool startedGame = false;

public:
  // Special
  StartMenu(); // Constructor

  // Fetches
  std::vector<MenuItem> getMenuItems();
  int getSelectedItem();
  bool getStartedGame();

  // Actions
  void draw();
  std::string update();
};