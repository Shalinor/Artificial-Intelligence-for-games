#include "Agent.h"

#include <iostream>

Agent::Agent(std::shared_ptr<Texture> texture_)
{
	texture = texture_;

	//Add behaviours to agent
	behaviours.push_back(make_shared<Wander>());

	behaviours.push_back(make_shared<KeyboardController>());
//	behaviours.push_back(make_shared<DrunkenModifier>());
	behaviours.push_back(make_shared<Seek>());
//	behaviours.push_back(make_shared<Flee>());

	//Set default/initial values
	maxSpeed = 1.f;
	heading = 0.f;

	position = vec2(250.f, 200.f);
	velocity = vec2(0.f);
	acceleration = vec2(0.f);

	targetPosition = position;
}

Agent::~Agent()
{

}

void Agent::Update(float deltaTime_)
{
	//TODO: Sensing Calculations
	//TODO: Thinking Calculations
	//			Add or remove behaviours from the behaviours list

	//Acting
	for (auto iterator = behaviours.begin(); iterator != behaviours.end(); ++iterator)
	{
		(*iterator)->Update(this, deltaTime_);
	}


	//TODO: Physics stuff with force, acceleration, velocity, etc...
	//Apply acceleration and decelerate if no acceleration
	if (acceleration.x != 0.0f)
	{
		velocity.x += (acceleration.x * (maxSpeed * deltaTime_));
	}
	else
	{
		velocity.x -= velocity.x * deltaTime_;
	}

	if (acceleration.y != 0.0f)
	{
		velocity.y += (acceleration.y * (maxSpeed * deltaTime_));
	}
	else
	{
		velocity.y -= velocity.y * deltaTime_;
	}

	//Limit velocity to maxSpeed
	if (velocity.x > maxSpeed)
	{
		velocity.x = maxSpeed;
	}
	else if (velocity.x < -maxSpeed)
	{
		velocity.x = -maxSpeed;
	}

	if (velocity.y > maxSpeed)
	{
		velocity.y = maxSpeed;
	}
	else if (velocity.y < -maxSpeed)
	{
		velocity.y = -maxSpeed;
	}

	//calulate agents heading
	heading = atan2f(velocity.y, velocity.x) + 3.141592f / 2.0f;

	//Clear acceleration - Not required as the acceleration is created anew within the keyboardController per frame 
	//acceleration = { 0.0f, 0.0f };

	//Apply velocity to position
	position += velocity;

	/*
	position.x += velocity.x;
	position.y += velocity.y;
	*/
}

void Agent::Draw(SpriteBatch* spriteBatch_)
{
	spriteBatch_->DrawSprite(texture.get(), position.x, position.y, 16.f, 16.f, heading);
}

void Agent::SetAcceleration(vec2 acceleration_)
{
	acceleration = acceleration_;
}

void Agent::AddForce(float force_)
{
	/*velocity*/acceleration *= force_;
}

void Agent::AddForce(vec2 force_)
{
	//velocity += force_ * deltaTime_;

	//Get the force required to change the agents direction towards its target and assign it to the acceleration
	acceleration = force_ - velocity;
}

vec2 Agent::GetNormalisedVelocity()
{
	vec2	normal = { 0.f, 0.f };

	if (velocity.x != 0.f || velocity.y != 0.f)
	{
		//Calculate magnitude in order to normalise
		float	magnitude = sqrtf(((velocity.x * velocity.x) + (velocity.y * velocity.y)));

		//Normalise velocity
		normal = (velocity / magnitude);

		float tempx = velocity.x / magnitude;
		float tempy = velocity.y / magnitude;
	}

	//Return normalised velocity
	return normal;
}