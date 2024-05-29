#include "gtest/gtest.h"
#include "../hFiles/GameEngine.h"

class generalTest : public testing::Test{
protected:

    void SetUp() override{
        playerTest = new Player;
        enemyTest = new Enemy;
        bulletTest = new Bullet;
        //Set up of 2 enemies and 2 projectiles for testing
        enemies.push_back(*enemyTest);
        enemies.push_back(*enemyTest);
        bullets.push_back(*bulletTest);
        bullets.push_back(*bulletTest);
    }
    void TearDown() override{
        for(auto enemie : enemies){
            Test::TearDown();
        }
        for(auto bulls:bullets)
            Test::TearDown();
    }

    Player* playerTest = nullptr;
    Enemy* enemyTest = nullptr;
    Bullet* bulletTest = nullptr;
    std::vector<Enemy> enemies;
    std::vector<Bullet> bullets;
};

//Testing Fixture: check for collisions between projectiles,enemies and player.

TEST_F(generalTest,collisionTest){
    GameEngine test;
    test.GameRun();
    for(int j = 0; j < enemies.size() ; j++){
        if(playerTest->getSprite().getGlobalBounds().intersects(enemies[j].getSprite().getGlobalBounds())){
            playerTest->setHpDamageGet();
            enemies[j].damageGet(1,enemies[j].gethpBar());
            std::cout << "Collision PLAYER <-> ENEMY:" << j << " SUCCEED " << std::endl;
        }
        EXPECT_TRUE(playerTest->getSprite().getGlobalBounds().intersects(enemies[j].getSprite().getGlobalBounds()));
        for(int i = 0; i < bullets.size(); i++){
            if(enemies[j].getSprite().getGlobalBounds().intersects(bullets[i].getSprite().getGlobalBounds()) && enemies[j].getDirection() != Dead){
                bullets.erase(bullets.begin() +i);
                std::cout << "\n Collision ENEMY:" << j <<"  <-> BULLET:" << i << " SUCCEED" << std::endl;
            }
            EXPECT_TRUE(enemies[j].getSprite().getGlobalBounds().intersects(bullets[i].getSprite().getGlobalBounds()));
        }
    }
}

