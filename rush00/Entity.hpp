#ifndef __ENTITY_HPP__
# define __ENTITY_HPP__

# include <string>

typedef unsigned int uint;

class Entity
{
protected:
	int _idx;
	int _x;
	int _y;
	int _dir;
	bool _canShoot;
	uint _maxx;
	uint _maxy;
	// the pattern to write on windows
	int _left;
	int _right;
	int _top;
	int _bottom;
	std::string _pattern;
public:
	Entity();
	Entity(const Entity &);
	virtual ~Entity();
	virtual Entity &operator=(const Entity &);
	// virtual void movex(int);
	// virtual void movey(int);
	virtual int getX() const;
	virtual int getY() const;
	virtual int getLeft() const;
	virtual int getRight() const;
	virtual int getTop() const;
	virtual int getBottom() const;
	virtual int getWidth() const;
	virtual int getHeight() const;
	virtual const std::string &getPattern() const;
	virtual void setLeft(int);
	virtual void setRight(int);
	virtual void setTop(int);
	virtual void setBottom(int);
	virtual void update() = 0;
	virtual bool canShoot();
	virtual void setIDX(int);
	virtual int getIDX();
	// virtual void move() = 0;
	// virtual int shoot() const = 0;
};

#endif
