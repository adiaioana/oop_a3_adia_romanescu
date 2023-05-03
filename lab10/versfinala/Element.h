#pragma once
template <typename K, typename V> struct Element {
	K Key;
	V Value;
	int Index;
	void operator =(Element <K, V> B)
	{
		Key = B.Key;
		Index = B.Index;
		Value = B.Value;
	}

};