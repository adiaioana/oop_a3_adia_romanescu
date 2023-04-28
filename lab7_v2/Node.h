#pragma once
template <typename tp> struct Node {
	public:
	Node <tp>* ant, *succ;
	public:
	tp info;
};