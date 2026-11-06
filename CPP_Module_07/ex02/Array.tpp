template <typename T>
Array<T>::Array()
{
	this->array = NULL;
	this->len = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->array = new T[n];
	this->len = n;
}

template <typename T>
Array<T>::Array(const Array<T>& before)
{
	this->len = before.len;
	this->array = NULL;
	if (this->len > 0)
	{
		this->array = new T[this->len];
		for (unsigned int i = 0; i < this->len; i++)
			this->array[i] = before.array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& before)
{
	if (this != &before)
	{
		delete[] this->array;
		this->array = NULL;
		this->len = before.len;
		if (this->len > 0)
		{
			this->array = new T[this->len];
			for (unsigned int i = 0; i < this->len; i++)
				this->array[i] = before.array[i];
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->len)
		throw (Array<T>::indexOutOfBounds());
	return (this->array[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->len)
		throw (Array<T>::indexOutOfBounds());
	return (this->array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->len);
}

