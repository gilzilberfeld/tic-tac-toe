#pragma once
class IllegalMove : public exception 
{
public:
	IllegalMove() : exception("Illegal Move!") {}
};