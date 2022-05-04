#pragma once

struct Size2D
{
public:
	Size2D(const float& w_ = 0.0, const float& h_ = 0.0)
		: w(w_), h(h_) {}
	
	float w, h;
};