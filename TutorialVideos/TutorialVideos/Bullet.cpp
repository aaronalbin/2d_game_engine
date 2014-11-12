#include "Bullet.h"

#include <Bengine/ResourceManager.h>


Bullet::Bullet(glm::vec2 pos, glm::vec2 dir, float speed, int lifeTime) {
	_position = pos;
	_direction = dir;
	_speed = speed;
	_lifeTime = lifeTime;
}


Bullet::~Bullet() {
}

void Bullet::draw(Bengine::SpriteBatch& spriteBatch) {
	glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);
	static Bengine::GLTexture texture = Bengine::ResourceManager::getTexture("Textures/jimmyJump_pack/PNG/CharacterRight_Standing.png");

	Bengine::Color color;
	color.r = 255;
	color.g = 255;
	color.g = 255;
	color.a = 255;

	glm::vec4 posAndSize = glm::vec4(_position.x, _position.y, 30.0f, 30.0f);
	spriteBatch.draw(posAndSize, uv, texture.id, 0.0f, color);
}

bool Bullet::update() {
	_position += _direction * _speed;
	_lifeTime--;
	if (_lifeTime == 0)
		return true;
	else
		return false;
}