
#include<iostream>
#include<math.h>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<string>
#include<cmath>
using namespace std;
using namespace sf;
int coins_count = 100;
double const pi = 3.1415926535897;
float MarginOfError = 1;
float TimeMarginOfError = 50;//milliseconds
float gravityforce = 0.9;
const int projectile_array_size = 50;
bool UpCollision(Sprite n1, Sprite n2) {

    Vector2f V1, V2, P1, P2;
    V1.y = n1.getTexture()->getSize().y * n1.getScale().y;
    V2.y = n2.getTexture()->getSize().y * n2.getScale().y;
    P1 = n1.getPosition();
    P2 = n2.getPosition();
    if (P1.y + V1.y - P2.y >= -MarginOfError && P1.y + V1.y < P2.y + V2.y) { return true; }
    else { return false; }
}
bool ProjectileUpCollision(float theta, Sprite n1, Sprite n2) {

    Vector2f V1, V2, P1, P2;
    V1.y = n1.getTexture()->getSize().y * n1.getScale().y * abs(sin(theta));
    V2.y = n2.getTexture()->getSize().y * n2.getScale().y;
    P1 = n1.getPosition();
    P2 = n2.getPosition();
    if (P1.y + V1.y - P2.y >= -MarginOfError && P1.y + V1.y < P2.y + V2.y) { return true; }
    else { return false; }
}
bool DownCollision(Sprite n1, Sprite n2) {

    Vector2f V1, V2, P1, P2;
    V1.y = n1.getTexture()->getSize().y * n1.getScale().y;
    V2.y = n2.getTexture()->getSize().y * n2.getScale().y;
    P1 = n1.getPosition();
    P2 = n2.getPosition();
    if (P1.y <= P2.y + V2.y + MarginOfError && P1.y >= P2.y) { return true; }
    else { return false; }


}

bool LeftCollision(Sprite n1, Sprite n2) {

    Vector2f V1, V2, P1, P2;
    V1.x = n1.getTexture()->getSize().x * n1.getScale().x;
    V2.x = n2.getTexture()->getSize().x * n2.getScale().x;
    P1 = n1.getPosition();
    P2 = n2.getPosition();
    if (P1.x + V1.x >= P2.x - MarginOfError && P1.x + V1.x <= P2.x + V2.x) { return true; }
    else { return false; }

}

bool RightCollision(Sprite n1, Sprite n2) {

    Vector2f V1, V2, P1, P2;
    V1.x = n1.getTexture()->getSize().x * n1.getScale().x;
    V2.x = n2.getTexture()->getSize().x * n2.getScale().x;
    P1 = n1.getPosition();
    P2 = n2.getPosition();
    if (P1.x <= P2.x + V2.x + MarginOfError && P1.x >= P2.x) { return true; }
    else { return false; }

}
bool DirectionUp(Sprite n1, Sprite n2) {
    Vector2f V1, V2, P1, P2;
    V1.y = n1.getTexture()->getSize().y * n1.getScale().y;
    V2.y = n2.getTexture()->getSize().y * n2.getScale().y;
    P1 = n1.getPosition();
    P2 = n2.getPosition();
    if (P1.y + V1.y < P2.y + V2.y) { return true; }

    else { return false; }

}
bool DirectionDown(Sprite n1, Sprite n2) {
    Vector2f V1, V2, P1, P2;
    V1.y = n1.getTexture()->getSize().y * n1.getScale().y;
    V2.y = n2.getTexture()->getSize().y * n2.getScale().y;
    P1 = n1.getPosition();
    P2 = n2.getPosition();
    if (P2.y + V2.y < P1.y) { return true; }

    else { return false; }

}
bool DirectionLeft(Sprite n1, Sprite n2) {
    Vector2f V1, V2, P1, P2;
    V1.x = n1.getTexture()->getSize().x * n1.getScale().x;
    V2.x = n2.getTexture()->getSize().x * n2.getScale().x;
    P1 = n1.getPosition();
    P2 = n2.getPosition();
    if (P1.x + V1.x < P1.x) { return true; }

    else { return false; }

}
bool DirectionRight(Sprite n1, Sprite n2) {
    Vector2f V1, V2, P1, P2;
    V1.x = n1.getTexture()->getSize().x * n1.getScale().x;
    V2.x = n2.getTexture()->getSize().x * n2.getScale().x;
    P1 = n1.getPosition();
    P2 = n2.getPosition();
    if (P2.x + V2.x < P2.x) { return true; }

    else { return false; }

}
bool xAxisIntersection(Sprite n1, Sprite n2) {
    Vector2f V1, V2, P1, P2;
    V1.x = n1.getTexture()->getSize().x * n1.getScale().x;
    V2.x = n2.getTexture()->getSize().x * n2.getScale().x;
    P1 = n1.getPosition();
    P2 = n2.getPosition();
    if (((P1.x - P2.x + V1.x) / V2.x > 0 && ((P1.x - P2.x + V1.x) / V2.x) < 1) || ((P1.x - P2.x) / V2.x > 0 && ((P1.x - P2.x) / V2.x) < 1)) { return true; }
    if (((P2.x - P1.x + V2.x) / V1.x > 0 && ((P2.x - P1.x + V2.x) / V1.x) < 1) || ((P2.x - P1.x) / V1.x > 0 && ((P2.x - P1.x) / V1.x) < 1)) { return true; }
}
bool yAxisIntersection(Sprite n1, Sprite n2) {
    Vector2f V1, V2, P1, P2;
    V1.y = n1.getTexture()->getSize().y * n1.getScale().y;
    V2.y = n2.getTexture()->getSize().y * n2.getScale().y;
    P1 = n1.getPosition();
    P2 = n2.getPosition();
    if (((P1.y - P2.y + V1.y) / V2.y > 0 && ((P1.y - P2.y + V1.y) / V2.y) < 1) || ((P1.y - P2.y) / V2.y > 0 && ((P1.y - P2.y) / V2.y) < 1)) { return true; }
    if (((P2.y - P1.y + V2.y) / V1.y > 0 && ((P2.y - P1.y + V2.y) / V1.y) < 1) || ((P2.y - P1.y) / V1.y > 0 && ((P2.y - P1.y) / V1.y) < 1)) { return true; }
}
bool ProjectileUpSideCollision(float theta, Sprite n1, Sprite n2) {
    if (ProjectileUpCollision(theta, n1, n2) == true && xAxisIntersection(n1, n2) == true)
    {
        return true;
    }
    else
    {
        return false;
    }

}







bool UpSideCollision(Sprite n1, Sprite n2) {
    if (UpCollision(n1, n2) == true && xAxisIntersection(n1, n2) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}bool DownSideCollision(Sprite n1, Sprite n2) {
    if (DownCollision(n1, n2) == true && xAxisIntersection(n1, n2) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool RightSideCollision(Sprite n1, Sprite n2) {
    if (RightCollision(n1, n2) == true && yAxisIntersection(n1, n2) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool LeftSideCollision(Sprite n1, Sprite n2) {
    if (LeftCollision(n1, n2) == true && yAxisIntersection(n1, n2) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

float GetSpriteSizeX(Sprite sprite) {
    float size;
    size = sprite.getTexture()->getSize().x * sprite.getScale().x;
    return size;


}
float GetSpriteSizeY(Sprite sprite) {
    float size;
    size = sprite.getTexture()->getSize().y * sprite.getScale().y;
    return size;


}
struct Character {

    Sprite sprite;
    Texture texture;
    Vector2f movement_vector;
    float  jump_distance = 10;
    int hp;
    Vector2f size;
    float firerate;
    bool gravityconstant = true;



};
struct Projectile
{
    Sprite sprite[projectile_array_size];
    Texture texture;
    Vector2f scale, movement_vector[projectile_array_size];
    bool cycle_constant[projectile_array_size] = { false,false,false,false,false,false,false,false,false,false }, timeconst = false;
    float theta;
    Clock clock;
    Time time;
    int clicks = 0, speed, projectile_count = 0, projectile_mouse_allowcount = 0, thrown_projectile_allowcount[projectile_array_size], projectile_hp_allowcount[projectile_array_size];
};
void AutoShoot(Character& Shooter, Character& Shot, Projectile& projectile, int& tilecount, Sprite tile[], bool gravityconstant) {

    projectile.time = projectile.clock.getElapsedTime();
    cout << projectile.time.asMilliseconds() << endl;
    if (projectile.time.asMilliseconds() > 1000 / (Shooter.firerate) - TimeMarginOfError && projectile.time.asMilliseconds() < 1000 / (Shooter.firerate) + TimeMarginOfError) {

        cout << "success" << endl;
        projectile.clock.restart();
        projectile.timeconst = true;

    }

    if (projectile.timeconst == false) { projectile.projectile_mouse_allowcount = 1; }
    if (projectile.timeconst == true && (projectile.projectile_mouse_allowcount == 1)) {
        if (projectile.projectile_count < projectile_array_size) { projectile.projectile_count = projectile.projectile_count + 1; }
        projectile.clicks = projectile.clicks + 1;
        projectile.projectile_mouse_allowcount = 0;
        if (projectile.clicks == projectile_array_size) { projectile.clicks = 0; for (int k = 0; k < projectile_array_size; k++) { projectile.cycle_constant[k] = true; } }
    }


    for (int i = 0; i < projectile.projectile_count; i++) {
        if (projectile.cycle_constant[projectile.clicks] == true) {
            projectile.thrown_projectile_allowcount[projectile.clicks] = 0;  projectile.sprite[projectile.clicks].setPosition(-4000, -4000);
            projectile.cycle_constant[projectile.clicks] = false;
        }
        if (projectile.thrown_projectile_allowcount[i] == 0) {
            projectile.sprite[i].setPosition(Shooter.sprite.getPosition());
            projectile.movement_vector[i].y = 0;
            projectile.movement_vector[i].x = 0;
            float dx, dx2, dy, theta, numerator, denominator, Sine, Cosine, r;
            projectile.sprite[i].setScale(projectile.scale);
            dy = Shot.sprite.getPosition().y - Shooter.sprite.getPosition().y;
            if (dy < 0) { dy = abs(dy); }
            else if (dy > 0) { dy = -1 * abs(dy); }
            dx = Shot.sprite.getPosition().x - Shooter.sprite.getPosition().x + GetSpriteSizeX(Shot.sprite) / 2;
            dx2 = dx;
            if (dx < 0) { dx = abs(dx); }
            r = sqrt(dx * dx + dy * dy);
            numerator = gravityforce * dx * dx + dy * projectile.speed * projectile.speed;
            denominator = projectile.speed * projectile.speed * r;
            theta = 0.5 * asin(numerator / denominator) + 0.5 * atan(dy / dx);
            if (dx2 < 0) { theta = pi - theta; }
            Sine = sin(theta);
            Cosine = cos(theta);
            projectile.movement_vector[i].y = projectile.movement_vector[i].y - projectile.speed * Sine;
            projectile.movement_vector[i].x = projectile.movement_vector[i].x + projectile.speed * Cosine;
            theta = ((theta) / (2 * pi)) * 360;
            cout << theta << endl;
        }
        projectile.thrown_projectile_allowcount[i] = 1;
        float theta;
        theta = abs(projectile.movement_vector[i].y / projectile.movement_vector[i].x);
        theta = atan(theta);
        theta = theta * 180 / pi;
        if (projectile.movement_vector[i].y < 0 && projectile.movement_vector[i].x > 0) { theta = -theta; }
        else if (projectile.movement_vector[i].y < 0 && projectile.movement_vector[i].x < 0) { theta = -180 + theta; }
        else if (projectile.movement_vector[i].y > 0 && projectile.movement_vector[i].x < 0) { theta = 180 - theta; }
        //cout << theta << endl;
        projectile.sprite[i].setRotation(-180 + theta);
        if (gravityconstant == true) {
            projectile.movement_vector[i].y = projectile.movement_vector[i].y + 0.9;
        }
        if (projectile.projectile_count)
            for (int x = 0; x < tilecount; x++) {
                if (projectile.sprite[i].getGlobalBounds().intersects(tile[x].getGlobalBounds())) {
                    projectile.sprite[i].setScale(0, 0);
                }
                if (projectile.sprite[i].getGlobalBounds().intersects(Shot.sprite.getGlobalBounds())) {
                    projectile.sprite[i].setScale(0, 0);
                    if (projectile.projectile_hp_allowcount[i] == 0) {
                        Shot.hp = Shot.hp - 5;
                        projectile.projectile_hp_allowcount[i] = 1;
                    }
                }
                else { projectile.projectile_hp_allowcount[i] = 0; }
            }
        projectile.sprite[i].move(projectile.movement_vector[i]);
    }
    projectile.timeconst = false;
}
//n1 is set to be above n2
void SetSpritePosition(Character& n1, Sprite& n2) {
    Vector2f V1;
    V1.y = n1.sprite.getTexture()->getSize().y * n1.sprite.getScale().y;
    n1.sprite.setPosition(n2.getPosition().x, n2.getPosition().y - V1.y - MarginOfError);
}
void CharacterCollision(Character& character, Sprite& Tile) {
    Vector2f V1, V2;
    V1.y = character.sprite.getTexture()->getSize().y * character.sprite.getScale().y;
    V1.x = character.sprite.getTexture()->getSize().x * character.sprite.getScale().x;
    V2.y = Tile.getTexture()->getSize().y * Tile.getScale().y;
    V2.x = Tile.getTexture()->getSize().y * Tile.getScale().x;
    if (DownSideCollision(character.sprite, Tile) == true) {
        if (character.movement_vector.y < 0) { character.sprite.setPosition(character.sprite.getPosition().x, Tile.getPosition().y + V2.y + MarginOfError);   character.movement_vector.y = 0; }
    }


    if (UpSideCollision(character.sprite, Tile) == true) {
        character.gravityconstant = false;
        if (character.movement_vector.y > 0) { character.sprite.setPosition(character.sprite.getPosition().x, Tile.getPosition().y - V1.y - MarginOfError); character.movement_vector.y = 0; }
    }

    if (RightSideCollision(character.sprite, Tile) == true) {
        if (character.movement_vector.x < 0) { character.sprite.setPosition(Tile.getPosition().x + MarginOfError + V2.x, character.sprite.getPosition().y); character.movement_vector.x = 0; }
    }



    if (LeftSideCollision(character.sprite, Tile) == true) {
        if (character.movement_vector.x > 0) { character.sprite.setPosition(Tile.getPosition().x - MarginOfError - V1.x, character.sprite.getPosition().y); character.movement_vector.x = 0; }
    }
}



void InitializeProjectile(Projectile& projectile, float scaleY, float scaleX, float projectile_speed) {
    projectile.speed = projectile_speed;
    projectile.scale.x = scaleX;
    projectile.scale.y = scaleY;


    for (int i = 0; i < projectile_array_size; i++) { projectile.thrown_projectile_allowcount[i] = 0; }
    for (int i = 0; i < projectile_array_size; i++) { projectile.projectile_hp_allowcount[i] = 0; }
    for (int k = 0; k < projectile_array_size; k++) {
        projectile.sprite[k].setTexture(projectile.texture);
        projectile.sprite[k].setPosition(-40000, -40000);
        projectile.sprite[k].setScale(projectile.scale);
    }
    for (int i = 0; i < projectile.projectile_count; i++) { projectile.movement_vector[i].x = 0; projectile.movement_vector[i].y = 0; }
}

void PlayerShootLeftClick(Character& Player, Character& enemy, Projectile& projectile, Vector2f& Mouseposition, int& tilecount, Sprite tile[], bool gravityconstant) {
    if (Mouse::isButtonPressed(Mouse::Button::Left) == false) { projectile.projectile_mouse_allowcount = 1; }
    if (Mouse::isButtonPressed(Mouse::Button::Left) == true && (projectile.projectile_mouse_allowcount == 1)) {
        if (projectile.projectile_count < projectile_array_size) { projectile.projectile_count = projectile.projectile_count + 1; }
        projectile.clicks = projectile.clicks + 1;
        projectile.projectile_mouse_allowcount = 0;
        if (projectile.clicks == projectile_array_size) { projectile.clicks = 0; for (int k = 0; k < projectile_array_size; k++) { projectile.cycle_constant[k] = true; } }
    }
    for (int i = 0; i < projectile.projectile_count; i++) {
        if (projectile.cycle_constant[projectile.clicks] == true) {
            projectile.thrown_projectile_allowcount[projectile.clicks] = 0;  projectile.sprite[projectile.clicks].setPosition(-4000, -4000);
            projectile.cycle_constant[projectile.clicks] = false;
        }
        if (projectile.thrown_projectile_allowcount[i] == 0) {
            float y, x, r, Sin, Cosine;
            projectile.sprite[i].setPosition(Player.sprite.getPosition().x + GetSpriteSizeX(Player.sprite) / 2, Player.sprite.getPosition().y);
            projectile.movement_vector[i].x = 0;
            projectile.movement_vector[i].y = 0;
            projectile.sprite[i].setScale(projectile.scale);
            y = Mouseposition.y - Player.sprite.getPosition().y;
            if (y < 0) { y = abs(y); }
            else if (y > 0) { y = -1 * abs(y); }
            x = Mouseposition.x - Player.sprite.getPosition().x;
            r = sqrt(x * x + y * y);
            Sin = y / r;
            Cosine = x / r;
            projectile.movement_vector[i].y = projectile.movement_vector[i].y - projectile.speed * Sin;
            projectile.movement_vector[i].x = projectile.movement_vector[i].x + projectile.speed * Cosine;
        }
        projectile.thrown_projectile_allowcount[i] = 1;
        float theta;
        theta = abs(projectile.movement_vector[i].y / projectile.movement_vector[i].x);
        theta = atan(theta);
        theta = theta * 180 / pi;
        if (projectile.movement_vector[i].y < 0 && projectile.movement_vector[i].x > 0) { theta = -theta; }
        else if (projectile.movement_vector[i].y < 0 && projectile.movement_vector[i].x < 0) { theta = -180 + theta; }
        else if (projectile.movement_vector[i].y > 0 && projectile.movement_vector[i].x < 0) { theta = 180 - theta; }
        //cout << theta << endl;
        projectile.sprite[i].setRotation(-180 + theta);
        if (gravityconstant == true) {
            projectile.movement_vector[i].y = projectile.movement_vector[i].y + 0.9;
        }
        if (projectile.projectile_count)
            for (int x = 0; x < tilecount; x++) {
                if (projectile.sprite[i].getGlobalBounds().intersects(tile[x].getGlobalBounds())) {
                    projectile.sprite[i].setScale(0, 0);
                }
                if (projectile.sprite[i].getGlobalBounds().intersects(enemy.sprite.getGlobalBounds())) {
                    projectile.sprite[i].setScale(0, 0);
                    if (projectile.projectile_hp_allowcount[i] == 0) {
                        enemy.hp = enemy.hp - 5;
                        projectile.projectile_hp_allowcount[i] = 1;
                    }
                }
                else { projectile.projectile_hp_allowcount[i] = 0; }
            }
        projectile.sprite[i].move(projectile.movement_vector[i]);
    }
}
void PlayerShootRightClick(Character& Player, Character& enemy, Projectile& projectile, Vector2f& Mouseposition, int& tilecount, Sprite tile[], bool gravityconstant) {
    if (Mouse::isButtonPressed(Mouse::Button::Right) == false) { projectile.projectile_mouse_allowcount = 1; }
    if (Mouse::isButtonPressed(Mouse::Button::Right) == true && (projectile.projectile_mouse_allowcount == 1)) {
        if (projectile.projectile_count < projectile_array_size) { projectile.projectile_count = projectile.projectile_count + 1; }
        projectile.clicks = projectile.clicks + 1;
        projectile.projectile_mouse_allowcount = 0;
        if (projectile.clicks == projectile_array_size) { projectile.clicks = 0; for (int k = 0; k < projectile_array_size; k++) { projectile.cycle_constant[k] = true; } }
    }
    for (int i = 0; i < projectile.projectile_count; i++) {
        if (projectile.cycle_constant[projectile.clicks] == true) {
            projectile.thrown_projectile_allowcount[projectile.clicks] = 0;  projectile.sprite[projectile.clicks].setPosition(-4000, -4000);
            projectile.cycle_constant[projectile.clicks] = false;
        }
        if (projectile.thrown_projectile_allowcount[i] == 0) {
            float y, x, r, Sin, Cosine;
            projectile.sprite[i].setPosition(Player.sprite.getPosition().x + GetSpriteSizeX(Player.sprite) / 2, Player.sprite.getPosition().y);
            projectile.movement_vector[i].x = 0;
            projectile.movement_vector[i].y = 0;
            projectile.sprite[i].setScale(projectile.scale);
            y = Mouseposition.y - Player.sprite.getPosition().y;
            if (y < 0) { y = abs(y); }
            else if (y > 0) { y = -1 * abs(y); }
            x = Mouseposition.x - Player.sprite.getPosition().x;
            r = sqrt(x * x + y * y);
            Sin = y / r;
            Cosine = x / r;
            projectile.movement_vector[i].y = projectile.movement_vector[i].y - projectile.speed * Sin;
            projectile.movement_vector[i].x = projectile.movement_vector[i].x + projectile.speed * Cosine;
        }
        projectile.thrown_projectile_allowcount[i] = 1;
        float theta;
        theta = abs(projectile.movement_vector[i].y / projectile.movement_vector[i].x);
        theta = atan(theta);
        theta = theta * 180 / pi;
        if (projectile.movement_vector[i].y < 0 && projectile.movement_vector[i].x > 0) { theta = -theta; }
        else if (projectile.movement_vector[i].y < 0 && projectile.movement_vector[i].x < 0) { theta = -180 + theta; }
        else if (projectile.movement_vector[i].y > 0 && projectile.movement_vector[i].x < 0) { theta = 180 - theta; }
        //cout << theta << endl;
        projectile.sprite[i].setRotation(-180 + theta);
        if (gravityconstant == true) {
            projectile.movement_vector[i].y = projectile.movement_vector[i].y + 0.9;
        }
        if (projectile.projectile_count)
            for (int x = 0; x < tilecount; x++) {
                if (projectile.sprite[i].getGlobalBounds().intersects(tile[x].getGlobalBounds())) {}
                else {
                    if (projectile.sprite[i].getGlobalBounds().intersects(tile[x].getGlobalBounds())) {
                        projectile.sprite[i].setScale(0, 0);
                    }
                    if (projectile.sprite[i].getGlobalBounds().intersects(enemy.sprite.getGlobalBounds())) {
                        projectile.sprite[i].setScale(0, 0);
                        if (projectile.projectile_hp_allowcount[i] == 0) {
                            enemy.hp = enemy.hp - 5;
                            projectile.projectile_hp_allowcount[i] = 1;
                        }
                    }
                    else { projectile.projectile_hp_allowcount[i] = 0; }
                }
            }
        projectile.sprite[i].move(projectile.movement_vector[i]);
    }
}

void items(int coins[], bool check, Sprite x, Sprite y) {
    //texure
    for (int i = 0; i < coins_count; i++) {
        //animation

        if (x.getLocalBounds().intersects(y.getGlobalBounds())) {
            check = true;
            break;
            coins_count--;
        }
        else {
            check = false;
            continue;
        }
    }
}
struct enemy {
    int health_bar = 100;
    bool check_player;
    bool is_dead;
};
void Enemy(bool check, bool check_dead, Sprite x, Sprite y, Sprite z) {
    int counter = 0;
    int another_counter = 0;
    int counter_die = 0;
    int conter_one_shoot = 0;
    int counter_looking = 0;
    int health = 100;
    int enemymovement = -3;


    // Sprite hitting;
    // Sprite enemy_normal;
   //  Sprite dead;
     //Sprite fire;

     //enemy moving 
    Texture enemy_run;
    //enemy_run.loadFromFile("enemyrunning.png");
    x.setTexture(enemy_run);
    x.setTextureRect(IntRect(33.6 * 12, 44, 50, 50));
    //enemy m$f$player
    Texture looking[4 + 1];
    looking[4].loadFromFile("enemylooking5.png");
    looking[0].loadFromFile("enemylooking1.png");
    looking[1].loadFromFile("enemylooking2.png");
    looking[2].loadFromFile("enemylooking3.png");
    looking[3].loadFromFile("enemylooking4.png");
    x.setTexture(looking[counter_looking]);
    //enemy taking shoots
    Texture hits[1 + 1];
    hits[1].loadFromFile("enemytookashot2.png");
    hits[0].loadFromFile("enemytookashot1.png");
    x.setTexture(hits[conter_one_shoot]);
    //enemy 4af player
    Texture enemy[6 + 1];
    enemy[0].loadFromFile("enemy1.png");
    enemy[1].loadFromFile("enemy2.png");
    enemy[2].loadFromFile("enemy3.png");
    enemy[3].loadFromFile("enemy4.png");
    enemy[4].loadFromFile("enemy5.png");
    enemy[5].loadFromFile("enemy6.png");
    enemy[6].loadFromFile("enemy7.png");
    x.setTexture(enemy[counter]);
    x.setPosition(100, 0);
    x.setOrigin(21, 25);
    Texture death[6 + 1];
    //enemy dying
    death[0].loadFromFile("enemydie1.png");
    death[1].loadFromFile("enemydie2.png");
    death[2].loadFromFile("enemydie3.png");
    death[3].loadFromFile("enemydie4.png");
    death[4].loadFromFile("enemydie5.png");
    death[5].loadFromFile("enemydie6.png");
    death[6].loadFromFile("enemydie7.png");
    x.setTexture(death[counter_die]);
    //enemy start fire
    Texture firing[4 + 1];
    firing[0].loadFromFile("enemyfire1.png");
    firing[1].loadFromFile("enemyfire2.png");
    firing[2].loadFromFile("enemyfire3.png");
    firing[3].loadFromFile("enemyfire4.png");
    firing[4].loadFromFile("enemyfire5.png");
    x.setTexture(enemy[another_counter]);
    if (x.getPosition().x - y.getPosition().x <= 10) {
        x.move(enemymovement, 0);
        while (enemymovement > -3)
        {
            //enemy running
            x.setTexture(enemy_run);
        }
        check = true;
        if (counter < 6) {
            counter++;

        }

        else {
            counter = 0;
        }
        x.setTexture(enemy[counter]);

    }
    else {
        if (counter_looking < 4) {
            counter++;
        }
        else
            counter_looking = 0;
        x.setTexture(looking[counter_looking]);
    }
    if (check = true) {
        //start fire

        if (another_counter < 4) {
            another_counter++;
        }
        else
        {
            counter = 0;
        }x.setTexture(enemy[another_counter]);
    }
    while (check_dead = false)
    {
        if (z.getGlobalBounds().intersects(x.getGlobalBounds())) {
            z.setScale(0, 0);
            health = health - 40;
            //enemy taking shoots
            if (conter_one_shoot < 1) {
                conter_one_shoot++;
            }
            else conter_one_shoot = 0;
            x.setTexture(enemy[conter_one_shoot]);

            if (health == 0) {
                check_dead = true;
                //animation while dying
                if (counter_die < 6) {
                    counter_die++;
                }
                else counter_die = 0;
                x.setTexture(enemy[counter_die]);
                x.setScale(0, 0);
            }
            else
            {
                check_dead = false;
            }
        }
    }

}
struct player {
    int health_bar = 100;
    bool is_dead;
};
void powerups(bool is_powerup, Sprite x, Sprite y, Sprite enemy, Sprite power) {
    int count = 0;
    if (x.getGlobalBounds().intersects(y.getGlobalBounds())) {
        is_powerup = true;
        count = 1;
        y.setScale(0, 0);
    }
    else
    {
        is_powerup = false;
        count = 0;
    }
    while (is_powerup = true)
    {
        //  Vector2f bulletdir;

        //  bullet.setPosition(0, 0);
        //  Vector2f mousePosition;
        //  mousePosition.x = Mouse::getPosition(window).x;
        //  mousePosition.y = Mouse::getPosition(window).y;
        //  if (Mouse::isButtonPressed(Mouse::Left)) {

         //     float dX, dY;
          //    dX = mousePosition.x - ash.getPosition().x;
            //  dY = mousePosition.y - ash.getPosition().y;

              //float r;

         //     r = sqrt(dY * dY + dX * dX);
           //   dX /= r;
            //  dY /= r;
            //  bulletdir.x = dX;
            //  bulletdir.y = dY;
            //  bullet.setPosition(ash.getPosition());
        //  }

         // bullet.move(bulletdir);

          /*==============================================================*/
          //power uped bullet animation::
        if (power.getGlobalBounds().intersects(enemy.getGlobalBounds())) {
            Texture enemy_onfire;
            enemy_onfire.loadFromFile("enemyonfire.png");
            power.setTexture(enemy_onfire);
            power.setTextureRect(IntRect(51.5 * 8, 65, 60, 60));
        }
    }
}
//void game_status(Window mygame, Event ev, Sprite x, Sprite y) {
  //  if (ev.type == sf::Event::LostFocus) {
  //      mygame.pause();
   // }
   // if (ev.type == sf::Event::GainedFocus)
   //     mygame.resume();
//}


int main()
{

    RenderWindow window(VideoMode(1280, 720), "Fall Of Duty");

    Vector2f screenresolution;
    screenresolution.y = 1080;
    screenresolution.x = 1920;
    //RenderWindow window(VideoMode(screenresolution.x, screenresolution.y), "Our game", Style::Fullscreen);
    window.setFramerateLimit(60);
    //Game data space:

    //Player data
    Character player;
    player.jump_distance = 10;
    player.movement_vector.x = 0; player.movement_vector.y = 0;
    player.hp = 100;
    player.texture.loadFromFile("Idle__000.png");
    player.sprite.setTexture(player.texture);
    player.sprite.setScale(0.2, 0.2);
    //background data
    Sprite Background[20];
    Texture BackgroundTexture;
    BackgroundTexture.loadFromFile("BG.png");
    for (int x = 0; x < 20; x++) {
        Background[x].setTexture(BackgroundTexture);

        Background[x].setPosition(x * 1280, -250);
        Background[x].setScale(1, 1.5);
    }
    //tile data
    Sprite tile[100];
    int tile_count = 100;
    Texture TileTexture;
    TileTexture.loadFromFile("Sand.png");
    for (int x = 0; x < tile_count; x++) {
        tile[x].setTexture(TileTexture);
        tile[x].setPosition(1000 + 62 * x, 1040);
        tile[x].setScale(0.5, 0.5);
    }
    tile[5].setPosition(tile[5].getPosition().x, tile[5].getPosition().y - 200);
    //collision data
    Vector2f V1, V2;
    V1.y = player.sprite.getTexture()->getSize().y * player.sprite.getScale().y;
    V1.x = player.sprite.getTexture()->getSize().x * player.sprite.getScale().x;
    V2.y = tile[0].getTexture()->getSize().y * tile[0].getScale().y;
    V2.x = tile[0].getTexture()->getSize().y * tile[0].getScale().x;

    SetSpritePosition(player, tile[tile_count / 2]);
    //Player Projectile data
    Projectile fire_ball;
    fire_ball.texture.loadFromFile("Pink ball.png");
    InitializeProjectile(fire_ball, 0.2, 0.2, 30);
    //water ball
    Projectile water_ball;
    water_ball.texture.loadFromFile("Water__01.png");
    InitializeProjectile(water_ball, 0.2, 0.2, 30);




    //gravity data


    // enemeies data

    Character enemy1;
    enemy1.hp = 100;
    enemy1.firerate = 1;
    enemy1.texture.loadFromFile("esso1.png");
    enemy1.sprite.setScale(0.3, 0.3);
    enemy1.sprite.setTexture(enemy1.texture);
    enemy1.size.x = enemy1.sprite.getTexture()->getSize().x * enemy1.sprite.getScale().x;
    enemy1.size.y = enemy1.sprite.getTexture()->getSize().y * enemy1.sprite.getScale().y;
    enemy1.sprite.setPosition(tile[5].getPosition().x, tile[5].getPosition().y - MarginOfError - enemy1.size.y);
    //camera data
    Vector2f PlayerCameraPosition;



    bool item_taken = false;
    float windowwidth = 1200;
    float windowheight = 600;
    //RenderWindow window(VideoMode(windowwidth, windowheight), "fall of duty");
    window.setFramerateLimit(60);
    Texture fireball;
    fireball.loadFromFile("fireball.png");
    Sprite bullet;
    bullet.setTexture(fireball);
    bullet.setTextureRect(IntRect(96 * 14, 96 * 16, 60, 60));

    //enemy struct
    enemy usus;
    Sprite enemies;

    Texture player1[4 + 1];

    player1[0].loadFromFile("playermove1.png");
    player1[1].loadFromFile("playermove2.png");
    player1[2].loadFromFile("playermove3.png");
    player1[3].loadFromFile("playermove4.png");
    Sprite ash;

    ash.setPosition(50, 0);
    int counter = 0;
    ash.setTexture(player1[counter]);

    ash.setOrigin(71, 96);
    /*  int counter2 = 0;
       Texture jumping[4];
       jumping[0].loadFromFile(".png");
       jumping[1].loadFromFile(".png");
       jumping[2].loadFromFile(".png");
       jumping[3].loadFromFile(".png");
       //Sprite player_juming;
       ash.setTexture(jumping[counter2]);*/

       //camera and time
    Vector2f screen_resulotion;
    screen_resulotion.x;
    Vector2f camera_position;
    camera_position.x = ash.getPosition().x + screen_resulotion.x / 2.f - 800;
    camera_position.y = ash.getPosition().y + screen_resulotion.y / 2.f;
    View playercamera(camera_position, screen_resulotion);
    //window.setView(playercamera);
    //enemy sprite


   // RectangleShape enemy(Vector2f(70, 50));
    RectangleShape ground(Vector2f(2000, 580));

    // CircleShape item(30, 30);
     //item.setFillColor(Color::Green);

    Vector2f bulletdir;

    bullet.setPosition(0, 0);
    //  enemy.setFillColor(Color::Blue);
     // item.setPosition(Vector2f());

     // enemy.setPosition(150, 50);
    ground.setPosition(0, 550);
    float gravity = 0.5, jump = -1;
    bool check_gravity = false;

    bool bullets = 0;
    Vector2f mousePosition;
    float projectilespeed = 1;

    // SoundBuffer song;
     //song.loadFromFile("game music.wav");
     //Sound sound;
     //sound.setBuffer(song);
     //sound.play();


    while (window.isOpen()) {//the game loop************************************************************************



        //correct mouse positioning code//
        Vector2i pixelPos = Mouse::getPosition(window);
        Vector2f mouse_position = window.mapPixelToCoords(pixelPos);
        //correct mouse positioning code//





        //camera code
        PlayerCameraPosition.x = player.sprite.getPosition().x + screenresolution.x / 2.f - 800;
        PlayerCameraPosition.y = screenresolution.y / 2.f;
        View PlayerCamera(PlayerCameraPosition, screenresolution);
        //window.setView(PlayerCamera);
        //camera code




        Event event;
        bool pause = false;
        bool resume = false;

        window.setFramerateLimit(60);
        Texture menu, menu1, menu2;





        //loading
        menu.loadFromFile("start.png");
        menu1.loadFromFile("start1.png");
        menu2.loadFromFile("pause.png");


        //sounds 

        //sounds 
    //	SoundBuffer song;
    //	song.loadFromFile("game music.wav");
    //	Sound sound;
    //	sound.setBuffer(song);
    //	sound.play();


        //sprites
        Sprite Menu;
        Menu.setTexture(menu);

        Sprite Menu1;
        Menu1.setTexture(menu1);

        Sprite Menu2;
        Menu2.setTexture(menu2);



        int cnt = 0;

        while (window.isOpen())
        {
            Event event;

            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }





            if (Mouse::isButtonPressed(Mouse::Left))
            {
                Vector2i mousePos = Mouse::getPosition(window);


                while (cnt == 0) {
                    if (mousePos.x > 512 && mousePos.x < 816 && mousePos.y>361 && mousePos.y < 432)
                    {
                        cnt = 1;
                    }
                    else if (mousePos.x > 512 && mousePos.x < 816 && mousePos.y>433 && mousePos.y < 505)
                    {
                        cnt = 2;

                    }
                    else if (mousePos.x > 512 && mousePos.x < 816 && mousePos.y>506 && mousePos.y < 578)
                    {
                        cnt = 3;
                    }
                }


            }


            window.clear();
            if (cnt == 0) {

                window.draw(Menu);

            }

            else if (cnt == 1) {
                //window.close();
                ///////////////


                mousePosition.x = Mouse::getPosition(window).x;
                mousePosition.y = Mouse::getPosition(window).y;


                //enemy function call
                Enemy(usus.check_player, usus.is_dead, enemies, ash, bullet);

                //window collision::
              //if (rec.getGlobalBounds().intersects(window.getGlobalBounds())) { }
              //  if (ash.getGlobalBounds().intersects(item.getGlobalBounds())) {
                  //  item_taken = true;
                //}
                //if (item_taken) {
                  //  coins_count--;
                    //cout << coins_count << endl;
                //}

                if (ash.getGlobalBounds().intersects(ground.getGlobalBounds())) {
                    gravity = 0;
                    jump = -1;
                }
                else
                    gravity = 0.5;
                ash.move(0, gravity);
                if (Keyboard::isKeyPressed(Keyboard::Right) && ash.getPosition().x < 1150)
                {
                    ash.move(1, 0);

                    ash.setScale(-1, 1);
                    if (counter < 3)
                        counter++;
                    else { counter = 0; }
                    ash.setTexture(player1[counter]);
                }


                if (Keyboard::isKeyPressed(Keyboard::Left) && ash.getPosition().x > 30)
                {
                    ash.move(-1, 0);

                    ash.setScale(1, 1);
                    if (counter < 3)
                        counter++;
                    else { counter = 0; }
                    ash.setTexture(player1[counter]);
                }



                if (Keyboard::isKeyPressed(Keyboard::Space)) {

                    check_gravity = true;


                }
                if (check_gravity == true) {
                    ash.move(0, jump);
                    //   if (counter2 < 3)
                      //     counter2++;
                       //else { counter2 = 0; }
                      // ash.setTexture(jumping[counter2]);
                    if (jump <= 0) {
                        jump += 0.001;
                    }
                    else check_gravity = false;
                } ash.setPosition(ash.getPosition());

                if (Mouse::isButtonPressed(Mouse::Left)) {

                    float dX, dY;
                    dX = mousePosition.x - ash.getPosition().x;
                    dY = mousePosition.y - ash.getPosition().y;

                    float r;

                    r = sqrt(dY * dY + dX * dX);
                    dX /= r;
                    dY /= r;
                    bulletdir.x = dX;
                    bulletdir.y = dY;
                    bullet.setPosition(ash.getPosition());
                }

                bullet.move(bulletdir);


                // if (bullets == 1) {
                  //   window.draw(bullet);
                 //}
                 //else
                   //  window.clear(bullet);

                window.clear();

                // if (item_taken)
                    // window.draw();
                window.draw(ash);
                window.draw(bullet);
                window.draw(enemies);
                window.draw(ground);
                window.display();


                ////////////
                if (Keyboard::isKeyPressed(Keyboard::Key::W) && player.gravityconstant == false) { player.movement_vector.y = player.movement_vector.y - player.jump_distance; }
                if (Keyboard::isKeyPressed(Keyboard::Key::S)) { player.movement_vector.y = player.movement_vector.y + 2; }
                if (Keyboard::isKeyPressed(Keyboard::Key::A)) { player.movement_vector.x = player.movement_vector.x - 5; }
                if (Keyboard::isKeyPressed(Keyboard::Key::D)) { player.movement_vector.x = player.movement_vector.x + 5; }
                for (int x = 0; x < tile_count; x++) { if (UpSideCollision(player.sprite, tile[x]) == false) { player.gravityconstant = true; } }


                for (int x = 0; x < tile_count; x++) { CharacterCollision(player, tile[x]); }

                if (player.gravityconstant == true) {
                    player.movement_vector.y = player.movement_vector.y + gravityforce;
                }

                player.sprite.move(player.movement_vector);
                player.movement_vector.x = 0;






                // PlayerShootLeftClick(player, enemy, water_ball, mouse_position, tile_count, tile,false);
                PlayerShootRightClick(player, enemy1, water_ball, mouse_position, tile_count, tile, true);
                AutoShoot(enemy1, player, fire_ball, tile_count, tile, true);


                if (enemy1.hp <= 0) { enemy1.sprite.setScale(0, 0); }
                if (player.hp <= 0) { player.sprite.setScale(0, 0); }










                //draw between
                for (int x = 0; x < 20; x++) {
                    window.draw(Background[x]);
                }
                for (int x = 0; x < tile_count; x++) { window.draw(tile[x]); }

                window.draw(player.sprite);
                for (int k = 0; k < projectile_array_size; k++) { window.draw(fire_ball.sprite[k]); }
                for (int k = 0; k < projectile_array_size; k++) { window.draw(water_ball.sprite[k]); }

                window.draw(enemy1.sprite);
                //draw between


                ////////////


                if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
                {
                    pause = true;


                }



                if (pause) {
                    window.draw(Menu2);


                    if (Mouse::isButtonPressed(Mouse::Left))
                    {
                        Vector2i mousePos = Mouse::getPosition(window);



                        if (mousePos.x > 519 && mousePos.x < 813 && mousePos.y>360 && mousePos.y < 431)
                        {

                            resume = true;
                            pause = false;
                        }


                        else if (mousePos.x > 519 && mousePos.x < 813 && mousePos.y>432 && mousePos.y < 504)
                        {
                            window.close();
                        }
                        else if (mousePos.x > 519 && mousePos.x < 813 && mousePos.y>505 && mousePos.y < 577)
                        {
                            window.close();
                        }



                    }




                    if (resume) {
                        window.clear();
                        if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
                            pause = true;
                            resume = false;
                        }

                    }


                }




            }


            else if (cnt == 2) {
                window.draw(Menu1);

            }
            else if (cnt == 3) {
                window.close();
            }


            window.display();

        }
    }

    return 0;
}