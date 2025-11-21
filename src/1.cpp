#include <raylib.h>

const float screenWidth = 750;
const float screenHeight = 700;

enum gameState
{
    menu,
    info_screen,
    Choose_screen,
    one_player_screen,
    two_player_screen,
    lose_screen,
    exit
};

gameState state;

class Button
{
protected:
    float RectangleWidthButton;
    float RectangleHeightButton;

public:
    Button() : RectangleWidthButton(150), RectangleHeightButton(50)
    {
    }
    static bool IsMouseOverButton(Rectangle button)
    {
        Vector2 mousePosition = GetMousePosition();
        return CheckCollisionPointRec(mousePosition, button);
    }
    virtual void DrawB() = 0;
    virtual void SceneAfter() = 0; // this function is to change between scenes
};
class StartButton : public Button
{
    Rectangle Start;

public:
    StartButton(float x, float y) : Button(), Start{x, y, RectangleWidthButton, RectangleHeightButton}
    {
    }
    void DrawB() override
    {
        DrawRectangleRec(Start, IsMouseOverButton(Start) ? YELLOW : WHITE);
    }
    void SceneAfter() override
    {

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {

            if (IsMouseOverButton(Start))
            {
                state = Choose_screen;
            }
        }
    }
};
class InfoButton : public Button
{
    Rectangle Info;

public:
    InfoButton(float x, float y) : Info{x, y, RectangleWidthButton, RectangleHeightButton}
    {
    }
    void DrawB() override
    {
        DrawRectangleRec(Info, IsMouseOverButton(Info) ? YELLOW : WHITE);
    }
    void SceneAfter() override
    {

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {

            if (IsMouseOverButton(Info))
            {
                state = info_screen;
            }
        }
    }
};
class ExitButton : public Button
{
    Rectangle Exit;

public:
    ExitButton(float x, float y) : Button(), Exit{x, y, RectangleWidthButton, RectangleHeightButton}
    {
    }
    void DrawB() override
    {
        DrawRectangleRec(Exit, IsMouseOverButton(Exit) ? YELLOW : WHITE);
    }
    void SceneAfter() override
    {

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {

            if (IsMouseOverButton(Exit))
            {
                state = exit;
            }
        }
    }
};
class BackButton : public Button
{
    Rectangle Back;

public:
    BackButton(float x, float y, float W, float H) : Button(), Back{x, y, W, H}
    {
    }

    void DrawB() override
    {
        DrawRectangleRec(Back, IsMouseOverButton(Back) ? YELLOW : WHITE);
    }
    void SceneAfter() override
    {

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {

            if (IsMouseOverButton(Back))
            {
                state = menu;
            }
        }
    }
};
class OnePlayerButton : public Button
{
    Rectangle PlayMode1;

public:
    OnePlayerButton(float x, float y) : Button(), PlayMode1{x, y, RectangleWidthButton, RectangleHeightButton}
    {
    }
    void DrawB() override
    {
        DrawRectangleRec(PlayMode1, IsMouseOverButton(PlayMode1) ? YELLOW : WHITE);
    }
    void SceneAfter() override
    {

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {

            if (IsMouseOverButton(PlayMode1))
            {
                state = one_player_screen;
            }
        }
    }
};
class TwoPlayerButton : public Button
{
    Rectangle PlayMode2p;

public:
    TwoPlayerButton(float x, float y) : Button(), PlayMode2p{x, y, RectangleWidthButton, RectangleHeightButton}
    {
    }
    void DrawB() override
    {
        DrawRectangleRec(PlayMode2p, IsMouseOverButton(PlayMode2p) ? YELLOW : WHITE);
    }
    void SceneAfter() override
    {

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {

            if (IsMouseOverButton(PlayMode2p))
            {
                state = two_player_screen;
            }
        }
    }
};

class SpaceShip
{
protected:
    Texture2D image;
    Vector2 position;

public:
    SpaceShip();
    virtual ~SpaceShip();
    virtual void draw();
    virtual void moveLeft();
    virtual void moveRight();
};

SpaceShip::SpaceShip()
{
    image = LoadTexture("../assets/spaceship.png");
    // If image fails to load, create a placeholder rectangle
    if (image.width == 0 || image.height == 0)
    {
        image.width = 50;
        image.height = 50;
    }
    position.x = (screenWidth / 2 - static_cast<float>(image.width) / 2.0f);
    position.y = (screenHeight - static_cast<float>(image.height) - 100.0f);
}

SpaceShip::~SpaceShip()
{
    UnloadTexture(image);
}

void SpaceShip::draw()
{
    DrawTextureV(image, position, WHITE);
}

void SpaceShip::moveLeft()
{
    if (IsKeyDown(KEY_LEFT))
    {
        position.x -= 5;
    }
    // Make sure the ship doesn't go off-screen
    if (position.x < 0)
    {
        position.x = 0;
    }
}

void SpaceShip::moveRight()
{
    if (IsKeyDown(KEY_RIGHT))
    {
        position.x += 5;
    }
    // Make sure the ship doesn't go off-screen
    if (position.x > screenWidth - static_cast<float>(image.width))
    {
        position.x = screenWidth - static_cast<float>(image.width);
    }
}

class Player2 : public SpaceShip
{
public:
    Player2()
    {
        image = LoadTexture("../assets/spaceship.png");
        // If image fails to load, create a placeholder rectangle
        if (image.width == 0 || image.height == 0)
        {
            image.width = 50;
            image.height = 50;
        }
        position.x = (screenWidth - static_cast<float>(image.width)) / 2 - 50;
        position.y = screenHeight - static_cast<float>(image.height) - 200;
    }
    ~Player2() override
    {
        UnloadTexture(image);
    }
    void moveLeft() override
    {
        if (IsKeyDown(KEY_A))
        {
            position.x -= 5;
        }
        // Make sure the ship doesn't go off-screen
        if (position.x < 0)
        {
            position.x = 0;
        }
    };
    void moveRight() override
    {
        if (IsKeyDown(KEY_D))
        {
            position.x += 5;
        }
        // Make sure the ship doesn't go off-screen
        if (position.x > screenWidth - static_cast<float>(image.width))
        {
            position.x = screenWidth - static_cast<float>(image.width);
        }
    }
};
Color BackGroundColor(int randomVariable)
{
    if (randomVariable >= 1 && randomVariable <= 10)
    {
        return RED;
    }
    else if (randomVariable >= 11 && randomVariable <= 20)
    {
        return BLUE;
    }
    else if (randomVariable >= 21 && randomVariable <= 30)
    {
        return YELLOW;
    }
    else if (randomVariable >= 31 && randomVariable <= 40)
    {
        return PINK;
    }
    return Color(BLANK);
}

int main()
{
    InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), "infinite");

    Button *startButton = new StartButton(screenWidth / 2 - 75, screenHeight / 2 - 25);
    Button *i = new InfoButton(screenWidth / 2 - 75, screenHeight / 2 + 50);
    Button *e = new ExitButton(screenWidth / 2 - 75, screenHeight / 2 + 125);
    Button *backButton = new BackButton(screenWidth - 30, 20, 25, 25);
    Button *onePlayerButton1 = new OnePlayerButton(screenWidth / 2 - 75, screenHeight / 2 - 25);
    Button *twoPlayerButton = new TwoPlayerButton(screenWidth / 2 - 75, screenHeight / 2 + 50);

    SpaceShip *p = new SpaceShip(); // Ensure the spaceship is created after window initialization
    SpaceShip *p2 = new Player2();

    Image qrCode = LoadImage("../assets/QrCode.png");
    Texture2D textureQr = LoadTextureFromImage(qrCode);
    UnloadImage(qrCode);

    Texture2D backgroundT = LoadTexture("../assets/background_stars.png");
    Vector2 positionOfBackGround = {0, 0};
    SetTargetFPS(60);

    Color BackgroundRandomColor = BackGroundColor(GetRandomValue(1, 40));
    while (!WindowShouldClose())
    {
        BeginDrawing();
        switch (state)
        {
        case menu:
            ClearBackground(BLACK);
            DrawTextureEx(backgroundT, positionOfBackGround, 0.0f, 8.5, BackgroundRandomColor);

            DrawText("Infinite  ", static_cast<int>(screenWidth) / 2 - 100, static_cast<int>(screenHeight) / 2 - 200, 60, ORANGE);
            // Draw Start Button
            startButton->DrawB();
            DrawText("Start", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 - 10, 30, ORANGE);
            startButton->SceneAfter();
            // Draw Info Button
            i->DrawB();
            DrawText("Info", GetScreenWidth() / 2 - 35, GetScreenHeight() / 2 - 10 + 75, 30, ORANGE);
            i->SceneAfter();
            // Draw Exit Button
            e->DrawB();
            DrawText("Exit", GetScreenWidth() / 2 - 35, GetScreenHeight() / 2 - 10 + 150, 30, ORANGE);
            e->SceneAfter();
            break;
        case info_screen:
            ClearBackground(BLACK);
            DrawTextureEx(backgroundT, positionOfBackGround, 0.0f, 8.5, PURPLE);

            DrawText("Thank you for trying my game.\n", 50, 10, 20, WHITE);
            DrawText(
                "\n\nGame Author Nour Mohammed",
                50, 40, 20, WHITE);
            backButton->DrawB();
            backButton->SceneAfter();
            DrawText("<--", static_cast<int>(screenWidth) - 25, 25, 15, ORANGE);
            DrawTexture(textureQr, GetScreenWidth() / 2 - 100, GetScreenHeight() / 2, WHITE);
            break;
        case Choose_screen:
            ClearBackground(BLACK);
            DrawTextureEx(backgroundT, positionOfBackGround, 0.0f, 8.5, PURPLE);
            // one player mode
            onePlayerButton1->DrawB();
            DrawText("OnePlayer", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 - 10, 25, ORANGE);
            onePlayerButton1->SceneAfter();

            // two player mode
            twoPlayerButton->DrawB();
            DrawText("TwoPlayer", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 + 65, 25, ORANGE);
            twoPlayerButton->SceneAfter();

            // Back button
            backButton->DrawB();
            backButton->SceneAfter();
            DrawText("<--", static_cast<int>(screenWidth) - 25, 25, 15, ORANGE);
            break;
        case one_player_screen:
            ClearBackground(BLACK);

            p->draw();
            p->moveLeft();
            p->moveRight();
            break;
        case two_player_screen:
            ClearBackground(BLACK);
            // player one
            p->draw();
            p->moveLeft();
            p->moveRight();

            p2->draw();
            p2->moveLeft();
            p2->moveRight();

            break;
        case lose_screen:
            break;
        case exit:
            CloseWindow();
            return 0;
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}