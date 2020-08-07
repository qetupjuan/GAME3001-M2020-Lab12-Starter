#include "Plane.h"
#include "TextureManager.h"

Plane::Plane()
{
	TextureManager::Instance()->loadSpriteSheet(
		"../Assets/sprites/atlas.txt",
		"../Assets/sprites/atlas.png", 
		"spritesheet");

	setSpriteSheet(TextureManager::Instance()->getSpriteSheet("spritesheet"));

	// set frame width
	setWidth(65);

	// set frame height
	setHeight(65);

	getTransform()->position = glm::vec2(400.0f, 200.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLANE);

	m_buildAnimations();

	m_angle = 0.0f;

	m_playerDetected = false;
	m_haveLOS = false;
}

Plane::~Plane()
= default;

void Plane::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the plane sprite with simple propeller animation
	TextureManager::Instance()->playAnimation(
		"spritesheet", getAnimation("plane"), x, y, 0.5f, m_angle, 255, true);
}

void Plane::update()
{
}

void Plane::clean()
{
}

void Plane::setAngle(float angle)
{
	m_angle = angle;
}

void Plane::m_buildAnimations()
{
	Animation planeAnimation = Animation();

	planeAnimation.name = "plane";
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("plane1"));
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("plane2"));
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("plane3"));

	setAnimation(planeAnimation);
}

void Plane::m_checkCurrentConditions()
{
	if (m_health >= 25)
	{
		if (m_playerDetected)
		{
			if (m_haveLOS)
			{
				if (m_withinMeleeRange)
				{
					m_stateMachine.setInnerState(MELEE_ATTACK);
				}
				else
				{
					m_stateMachine.setInnerState(MOVE_TO_MEELE);
				}
			}
			else
			{
				m_stateMachine.setInnerState(MOVE_TO_LOS);
			}
		}
	}
	else
	{
		m_stateMachine.setOuterState(FLIIGHT);
	}
}
