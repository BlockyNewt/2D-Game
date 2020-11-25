#include "Tile.h"

Tile::Tile(float positionX, float positionY, float tileSizeXY, int type)
{
	/*
		SET SETTINGS
	*/
	this->tile_.setPosition(sf::Vector2f(positionX, positionY));
	this->tile_.setSize(sf::Vector2f(tileSizeXY, tileSizeXY));
	this->tile_.setOutlineColor(sf::Color::Transparent);
	this->tile_.setOutlineThickness(1.f);

	this->type_Conversion_ = type;
	this->type_ = TYPE::DEFAULT;

	/*
		CANNOT PASS A TYPE THROUGH FOR SAVING AND LOADING FROM FILE REASONS

		CHECK WHICH TYPE OF TILE IT IS BASED OFF THE INT BEING PASSED
	*/
	switch (this->type_Conversion_)
	{
	case 0:
		this->type_ = TYPE::DEFAULT;
		this->tile_.setFillColor(sf::Color::Transparent);
		break;
	case 1:
		this->type_ = TYPE::BOUNDARY;
		this->tile_.setFillColor(sf::Color::Yellow);
		break;
	default:
		break;
	}
}

Tile::Tile(float positionX, float positionY, float tileSizeXY, const sf::Texture& texture, const sf::IntRect& textureBounds, int type)
{
	/*
		SET SETTINGS
	*/
	this->tile_.setPosition(sf::Vector2f(positionX, positionY));
	this->tile_.setSize(sf::Vector2f(tileSizeXY, tileSizeXY));
	this->tile_.setOutlineColor(sf::Color::Transparent);
	this->tile_.setOutlineThickness(0.f);
	this->tile_.setTexture(&texture);
	this->tile_.setTextureRect(textureBounds);
	std::cout << "LEFT: " << this->tile_.getTextureRect().left << " TOP: " << this->tile_.getTextureRect().top << std::endl;

	this->type_Conversion_ = type;
	this->type_ = TYPE::DEFAULT;

	/*
		CANNOT PASS A TYPE THROUGH FOR SAVING AND LOADING FROM FILE REASONS

		CHECK WHICH TYPE OF TILE IT IS BASED OFF THE INT BEING PASSED
	*/
	switch (this->type_Conversion_)
	{
	case 1:
		this->type_ = TYPE::BOUNDARY;
		//this->tile_.setFillColor(sf::Color::Yellow);
		break;
	default:
		break;
	}
}

Tile::~Tile()
{
}

void Tile::render(sf::RenderTarget& target)
{
	target.draw(this->tile_);
}

void Tile::setFillColor(const sf::Color& fillColor)
{
	this->tile_.setFillColor(fillColor);
}

void Tile::setOutlineColor(const sf::Color& outlineColor)
{
	this->tile_.setOutlineColor(outlineColor);
}

const sf::Vector2f& Tile::getPosition() const
{
	return this->tile_.getPosition();
}

const TYPE& Tile::getType() const
{
	return this->type_;
}

const int& Tile::getTypeConversion() const
{
	return this->type_Conversion_;
}

const sf::FloatRect Tile::getGlobalBounds() const
{
	return this->tile_.getGlobalBounds();
}

const float Tile::getLeftPosition() const
{
	return this->tile_.getGlobalBounds().left;
}

const float Tile::getRightPosition() const
{
	return this->tile_.getGlobalBounds().left + this->tile_.getGlobalBounds().width;
}

const float Tile::getTopPosition() const
{
	return this->tile_.getGlobalBounds().top;
}

const float Tile::getBottomPosition() const
{
	return this->tile_.getGlobalBounds().top + this->tile_.getGlobalBounds().height;
}

const sf::RectangleShape& Tile::getTile() const
{
	return this->tile_;
}

const sf::IntRect& Tile::getTextureBounds() const
{
	return this->tile_.getTextureRect();
}
