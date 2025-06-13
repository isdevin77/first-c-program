#include <SDL3/SDL.h>
#include <stdbool.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 100
#define BALL_SIZE 10
#define BALL_SPEED 5

typedef struct {
    SDL_FRect rect;
    int speed;
} Paddle;

typedef struct {
    SDL_FRect rect;
    float velX, velY;
} Ball;

void movePaddle(Paddle *paddle, int direction) {
    paddle->rect.y += direction * paddle->speed;
    if (paddle->rect.y < 0) paddle->rect.y = 0;
    if (paddle->rect.y > SCREEN_HEIGHT - PADDLE_HEIGHT) paddle->rect.y = SCREEN_HEIGHT - PADDLE_HEIGHT;
}

void updateBall(Ball *ball, Paddle *leftPaddle, Paddle *rightPaddle) {
    ball->rect.x += ball->velX;
    ball->rect.y += ball->velY;

    if (ball->rect.y <= 0 || ball->rect.y >= SCREEN_HEIGHT - BALL_SIZE) ball->velY *= -1;

    // Cast to SDL_Rect for intersection test
    SDL_Rect ballRect = { (int)ball->rect.x, (int)ball->rect.y, (int)ball->rect.w, (int)ball->rect.h };
    SDL_Rect leftRect = { (int)leftPaddle->rect.x, (int)leftPaddle->rect.y, (int)leftPaddle->rect.w, (int)leftPaddle->rect.h };
    SDL_Rect rightRect = { (int)rightPaddle->rect.x, (int)rightPaddle->rect.y, (int)rightPaddle->rect.w, (int)rightPaddle->rect.h };

    if (SDL_HasRectIntersection(&ballRect, &leftRect) || SDL_HasRectIntersection(&ballRect, &rightRect))
        ball->velX *= -1;

    if (ball->rect.x < 0 || ball->rect.x > SCREEN_WIDTH) {
        ball->rect.x = SCREEN_WIDTH / 2.0f;
        ball->rect.y = SCREEN_HEIGHT / 2.0f;
    }
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("SDL3 Pong", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    Paddle leftPaddle = {{50.0f, SCREEN_HEIGHT / 2.0f - PADDLE_HEIGHT / 2.0f, PADDLE_WIDTH, PADDLE_HEIGHT}, 8};
    Paddle rightPaddle = {{SCREEN_WIDTH - 60.0f, SCREEN_HEIGHT / 2.0f - PADDLE_HEIGHT / 2.0f, PADDLE_WIDTH, PADDLE_HEIGHT}, 8};
    Ball ball = {{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, BALL_SIZE, BALL_SIZE}, BALL_SPEED, BALL_SPEED};

    int running = 1;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = 0;
        }

        
    const bool *keys = SDL_GetKeyboardState(NULL);
    if (keys[SDL_SCANCODE_W]) movePaddle(&leftPaddle, -1);
    if (keys[SDL_SCANCODE_S]) movePaddle(&leftPaddle, 1);
    if (keys[SDL_SCANCODE_UP]) movePaddle(&rightPaddle, -1);
    if (keys[SDL_SCANCODE_DOWN]) movePaddle(&rightPaddle, 1);

        updateBall(&ball, &leftPaddle, &rightPaddle);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &leftPaddle.rect);
        SDL_RenderFillRect(renderer, &rightPaddle.rect);
        SDL_RenderFillRect(renderer, &ball.rect);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
