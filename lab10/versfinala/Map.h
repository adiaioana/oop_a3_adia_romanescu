#pragma once
#include <fstream>
#include "Element.h"
std::ofstream fout("a.txt");
template <typename K, typename V> class Map {
	private:
	int max_size;
		int count; 
	Element <K,V> *lista;
	public:
	Map();
	~Map();
	void DoubleAlloc();

	void Set(const K& key, V value);
	bool Delete(const K& key);
	void Clear();
	V& operator [](const K key);
	bool Get(const K& key, V& value);
	bool Includes(const Map<K, V>& map);

	class Iterator {
	private:
		Element <K, V>* ptr;
	//	Iterator(K a, V b, int x) :Element<K,V> *(ptr) {}
	public:
		Iterator operator++ ()
		{
			*this++;
			return &this;
		}
		bool operator !=(const Iterator& Second)
		{
			return (ptr != Second.ptr);
		}
		Element<K,V> operator *()
		{
			return Element<K,V> (*ptr);
		}

		Iterator begin()
		{
			return Iterator(lista);
		}
		Iterator end()
		{
			return Iterator(lista + count);
		}
	};

	auto begin() {
		return lista;
	}

	auto end() {
		return lista + count;
	}

};

template<typename K, typename V>
inline Map<K, V>::Map()
{
	fout << "Map constructed\n";
	max_size = 4;
	lista = new Element<K,V>[max_size];
	for (int i = 0; i < max_size; ++i){
		lista[i].Index = i;
	}
	count = 0;
}




template<typename K, typename V>
inline Map<K, V>::~Map()
{
	fout << "Map deconstructed\n";
	delete[] lista;
	count = 0;
	max_size = 4;
}

template<typename K, typename V>
inline void Map<K, V>::DoubleAlloc()
{
	fout << "Double Alloc to double "<<max_size<<"\n";
	Element<K,V>* aux = new Element<K,V>[max_size * 2];
	for (int i = 0; i < max_size; ++i)
		aux[i] = lista[i];
	max_size = max_size * 2;
	delete[] lista;
	lista = new Element<K,V> [max_size];
	for (int i = 0; i < max_size; ++i)
	{
		lista[i] = aux[i];
		lista[i].Index = i + 1;
	}
}

template<typename K, typename V>
inline void Map<K, V>::Set(const K& key, V value)
{
	fout << "Setting " << key<< " with "<<value << "\n";
	for (int i = 0; i < count; ++i)
		if (lista[i].Key == key) {
			lista[i].Value = value;
			return;
		}
	fout << "Initializing..." << "\n";
	if (count == max_size)
		this->DoubleAlloc();
	lista[count].Key = key;
	lista[count].Index = count + 1;
	lista[count].Value = value;
	count++;
}


template<typename K, typename V>
inline void Map<K, V>::Clear()
{
	fout << "Map cleared" << '\n';
	for (int i = 0; i < count; ++i)
	{
		lista[i].Key = 0;
		lista[i].Value = 0;
		lista[i].Index = 0;
	}
	count = 0;
}

template<typename K, typename V>
inline V& Map<K, V>::operator[](const K key)
{
	fout << "Accesed " << key << "\n";
	for (int i = 0; i < count; ++i)
		if (lista[i].Key == key)
			return lista[i].Value;
	if (count == max_size)
		this->DoubleAlloc();
	lista[count].Key = key; lista[count].Index = count; count++;
	return lista[count-1].Value;
}


template<typename K, typename V>
inline bool Map<K, V>::Delete(const K& key)
{
	fout << "Deleted value from key " << key << "\n";
	for (int i = 0; i < count; ++i)
		if(lista[i].Key==key)
		{
			lista[i].Key = lista[i].Value = 0;
			for (int j = i; j < count - 1; j++)
			{
				lista[j] = lista[j + 1];
				lista[j].Index--;
			}
			count--;
			return 1;
		}
	return 0;
}

template<typename K, typename V>
inline bool Map<K, V>::Get(const K& key, V& value)
{
	fout << "Getting value from key " << key;
	for (int i = 0; i < count; ++i)
		if (lista[i].Key == key)
		{
			fout << " , it's " << lista[i].Value << " !\n";
			value = lista[i].Value;
			return true;
		}

	return false;
}

template<typename K, typename V>
inline bool Map<K, V>::Includes(const Map<K, V>& map)
{
	fout << "Checking if a map includes another one... " << '\n';

	for (int i = 0; i < this->count; ++i) 
	{
		bool ok = 0;
		for (int j = 0; j < map.count; ++j)
			if (map.lista[j].Key == this->lista[i].Key)
				ok = 1;
		if (!ok)
		{
			fout << "Apparently not, key " << this->lista[i].Key << " doesn't appear\n";
			return false;
		}
	}
	
	fout << "Yes! It's included";
	return true;
}
