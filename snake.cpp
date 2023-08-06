#include <iostream>
#include <vector>

using namespace std;

class Snake {
public:
  Snake(int x, int y) {
    body.push_back(make_pair(x, y));
    direction = 'd';
  }

  void move() {
    int head_x = body[0].first;
    int head_y = body[0].second;

    switch (direction) {
      case 'u':
        head_y--;
        break;
      case 'd':
        head_y++;
        break;
      case 'l':
        head_x--;
        break;
      case 'r':
        head_x++;
        break;
    }

    body.insert(body.begin(), make_pair(head_x, head_y));

    if (body.size() > 1 && body[0] == body[1]) {
      game_over = true;
    }

    if (head_x < 0 || head_x >= width || head_y < 0 || head_y >= height) {
      game_over = true;
    }

    body.pop_back();
  }

  void turn(char key) {
    switch (key) {
      case 'u':
        if (direction != 'd') {
          direction = 'u';
        }
        break;
      case 'd':
        if (direction != 'u') {
          direction = 'd';
        }
        break;
      case 'l':
        if (direction != 'r') {
          direction = 'l';
        }
        break;
      case 'r':
        if (direction != 'l') {
          direction = 'r';
        }
        break;
    }
  }

  bool is_game_over() {
    return game_over;
  }

private:
  vector<pair<int, int>> body;
  char direction;
  bool game_over;
};

int main() {
  int width = 20;
  int height = 20;

  Snake snake(10, 10);

  while (!snake.is_game_over()) {
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        if (i == snake.body[0].first && j == snake.body[0].second) {
          cout << "O";
        } else if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
          cout << "#";
        } else {
          cout << " ";
        }
      }
      cout << endl;
    }

    char key;
    cin >> key;

    snake.turn(key);
    snake.move();
  }

  cout << "Game over!" << endl;

  return 0;
}
