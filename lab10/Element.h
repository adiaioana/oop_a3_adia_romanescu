#pragma once
template <typename K, typename V> struct Element {
	K Key;
	V Value;
	int Index;
	bool NotInit;
	void operator =(Element <K, V> B)
	{
		Key = B.Key;
		Index = B.Index;
		Value = B.Value;
		NotInit = B.NotInit;
	}

};