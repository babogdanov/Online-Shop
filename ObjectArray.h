//#pragma once
//template <class T>
//class ObjectArray
//{
//private:
//	T* objects;
//	int objectsCount;
//	T currentObject;
//
//public:
//	ObjectArray()
//	{
//		this->objects = nullptr;
//		this->objectsCount = 0;
//	}
//
//	ObjectArray(const ObjectArray& other)
//	{
//		this->objectsCount = other.objectsCount;
//		for (int i = 0; i < this->objectsCount; i++)
//		{
//			this->objects[i] = other.objects[i];
//		}
//		this->currentObject = other.currentObject;
//	}
//
//	ObjectArray& operator=(const ObjectArray& other)
//	{
//		if (this != &other)
//		{
//			this->objectsCount = other.objectsCount;
//			delete[] this->objects;
//			for (int i = 0; i < this->objectsCount; i++)
//			{
//				this->objects[i] = other.objects[i];
//			}
//			delete this->currentObject;
//			this->currentObject = other.currentObject;
//		}
//	}
//
//	~ObjectArray()
//	{
//		delete[] objects;
//	}
//
//	void setObjectsCount(int count)
//	{
//		this->objectsCount = count;
//	}
//	int getObjectsCount() const
//	{
//		return this->objectsCount;
//	}
//	T* getObjects() const
//	{
//		return this->objects;
//	}
//
//	void addObject(T object)
//	{
//		if (this->objectsCount > 0)
//		{
//			T* temp = new T[this->objectsCount];
//			for (int i = 0; i < this->objectsCount; i++)
//			{
//				temp[i] = this->objects[i];
//			}
//			delete[] objects;
//			this->objectsCount++;
//			objects = new T[objectsCount];
//			for (int i = 0; i < objectsCount - 1; i++)
//			{
//				this->objects[i] = temp[i];
//			}
//			this->objects[objectsCount - 1] = object;
//			delete[] temp;
//		}
//
//		else
//		{
//			this->objectsCount++;
//			this->objects = new T[this->objectsCount];
//			this->objects[0] = object;
//		}
//	}
//
//	void removeObject(T object)
//	{
//		for (int i = 0; i < this->objectsCount; i++)
//		{
//			if (this->objects[i] == object)
//			{
//				int j = i;
//				this->objectsCount--;
//				T* temp = new T[this->objectsCount];
//				for (int k = 0; k <= this->objectsCount; k++)
//				{
//					if (k == j)
//					{
//						continue;
//					}
//					temp[k] = this->objects[k];
//				}
//				delete[] objects;
//				objects = new T[this->objectsCount];
//				for (int i = 0; i < this->objectsCount; i++)
//				{
//					this->objects[i] = temp[i];
//				}
//				delete[] temp;
//			}
//		}
//	}
//
//	void printCurrentObject()
//	{
//		this->currentObject.print();
//	}
//
//	void print() const
//	{
//		for (int i = 0; i < this->objectsCount; i++)
//		{
//			this->objects[i].print();
//		}
//	}
//	void deleteObjects()
//	{
//		this->~ObjectArray();
//		this->objectsCount = 0;
//	}
//
//};
