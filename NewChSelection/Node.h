#pragma once


template <typename T> struct Node {
	struct Node* Next;
	T Data;
};

