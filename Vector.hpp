
#ifndef Vector_h
#define Vector_h

using namespace cop4530;

template<typename T>
Vector<T>::Vector() : theSize(0), theCapacity(0), array(nullptr){}





template <typename T>
Vector<T>::Vector(const Vector& rhs)
{
	theSize = rhs.size;
	theCapacity = rhs.theCapacity;
	array = new T[rhs.theCapacity];
	for (int i = 0; i < theSize; i++)
	{
		array[i] = rhs.array[i];
	}
}
template <typename T>
Vector<T>::Vector(Vector&& rhs)
{
	theSize = rhs.theSize;
	theCapacity = rhs.theCapacity;
	array = rhs.array;
	rhs.theSize = 0;
	rhs.theCapacity = 0;
	rhs.array = nullptr;
}

template<typename T>
Vector<T>::Vector(int num, const T& val)
{
	theCapacity = num;
    theSize = num;
	array = new T[theCapacity];
	for (int i = 0; i < theCapacity; i++)
	{
		array[i] = val;
	}
}

template <typename T>
Vector<T>::Vector(const_iterator start, const_iterator end)
{
    theSize = 0;
    theCapacity = 0;
    auto itr = start;
    array = new T[theCapacity];
	while(itr!=end)
    {
push_back(*itr);
itr++;
    }
	
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] array;
}

template<typename T>
 T& Vector<T>::operator[](int index)
{
	 return array[index];
}

 template<typename T>
 const T& Vector<T>::operator[](int index) const
 {
	 return array[index];
 }

 template<typename T>
 const Vector<T>& Vector<T>::operator=(const Vector &rhs)
 {
    theSize = rhs.theSize;
    theCapacity = rhs.theCapacity;
	 array = new T[rhs.theCapacity];
	 for (int i = 0; i < theSize; i++)
	 {
		 array[i] = rhs.array[i];
	 }
	 return this;
 } 

 template<typename T>
 Vector<T>& Vector<T>::operator=(Vector && rhs)
 {
	 theSize = rhs.theSize;
	 theCapacity = rhs.theCapacity;
	 array = new T[rhs.theCapacity];
	 for (int i = 0; i < theSize; i++)
	 {
		 array[i] = rhs.array[i];
	 }
	 return array;
 } 

 template<typename T>
  T& Vector<T>::at(int loc)
 {
	  if (loc >= theSize || loc<0)
	  {
		  throw 0;
	 }
	  else
	  {
		  return array[loc];
	  }
 }

  template<typename T>
  const T& Vector<T>::at(int loc) const
  {
	  if (loc >= theSize || loc < 0)
	  {
		  throw 0;
	  }
	  else
	  {
		  return array[loc];
	  }
  }

  template<typename T>
  T& Vector<T>::front()
  {
	  return array[0];
  }

  template<typename T>
  const T& Vector<T>::front() const
  {
	  return array[0];
  }

  template<typename T>
  T& Vector<T>::back()
  {
	  return array[theSize - 1];
  }

  template<typename T>
  const T& Vector<T>::back() const
  {
	  return array[theSize - 1];
  }

  template<typename T>
  int Vector<T>::size() const
  {
	  return theSize;
  }

  template<typename T>
  int Vector<T>::capacity() const
  {
	  return theCapacity;
  }

  template<typename T>
   bool Vector<T>::empty() const
  {
	   return (theSize == 0);
  }

   template<typename T>
   void Vector<T>::clear()
   {
	   while(!empty())
       {
        pop_back();
       }
   }

   template<typename T>
   void Vector<T>::push_back(const T& val)
   {
	   if (theSize == theCapacity)
	   {
		   doubleCapacity();
	   }
		   array[theSize] = val;
		   theSize++;
   }

   template<typename T>
   void Vector<T>::pop_back()
   {
	   theSize--;
   }

   template<typename T>
   void Vector<T>::resize(int num, T val)
   {
	   if (num > theCapacity)
	   {
		   reserve(num);
	   }

	   if (num > theSize)
	   {
		   for (int i = theSize - 1; i < num; i++)
		   {
			   array[i] = val;
		   }
		   theSize = num;
	   }
	   else
	   {
		  theSize=num;
	   }
	   
   }

   template<typename T>
   void Vector<T>::reserve(int newCapacity)
   {
	   if (newCapacity > theCapacity)
	   {
		   T* temp = new T[newCapacity];
		   for (int i = 0; i < theSize; i++)
		   {
			   temp[i] = array[i];
		   }
		   delete[] array;
		   array = temp;
		   theCapacity = newCapacity;
	   }
   }

   template<typename T>
   void Vector<T>::print(std::ostream& os, char ofc) const
   {
	   for (int i = 0; i < theSize; i++)
	   {
		   os << array[i] << ofc;
	   }
   }




   template<typename T>
   typename Vector<T>::iterator Vector<T>::begin()
   {
	   return &array[0];
   }

   template<typename T>
   typename Vector<T>::const_iterator Vector<T>::begin() const
   {
	   return &array[0];
   }

   template<typename T>
   typename Vector<T>::iterator Vector<T>::end()
   {
	   return &array[theSize];
   }

   template<typename T>
   typename Vector<T>::const_iterator Vector<T>::end() const
   {
	   return &array[theSize];
   }

   template<typename T>
   typename Vector<T>::iterator Vector<T>::insert(iterator itr, const T& val)
   {

    int k =0;
	   if (theSize == theCapacity)
	   {
		   doubleCapacity();
	   }

       theSize++;

	  for(int i = 0; i < theSize;i++)
      {
        if(array[i] == *itr)
        {
k = i;
        }
      }
        for(int j = theSize;j>k;j--)
        {
array[j] = array[j-1];
        }

    array[k] = val;

	   return &array[k];
   }

   template<typename T>
   typename Vector<T>::iterator Vector<T>::erase(iterator itr)
   {
    int k =0;
	 for(int i = 0; i < theSize;i++)
     {
        if(array[i] == *itr)
        {
            k=i;
        }
     }
     for(int j = k; j < theSize;j++)
     {
        array[j] = array[j+1];
     }
     theSize--;
     return &array[k];
   }

   template<typename T>
   typename Vector<T>::iterator Vector<T>::erase(iterator start, iterator end)
   {
	   int o=0, k =0;
       for(int i = 0;i< theSize;i++)
       {
        if(array[i] == *start)
        {
            k = i;
        }
        if(array[i] == *end)
        {
            o = i;
        }
       }

       for(int j = k;j<theSize;j++)
       {
array[j] = array[o];
o++;
theSize--;
       }
       theSize--;
       return &array[k];
   }

   template<typename T>
   void Vector<T>::doubleCapacity()
   {
	   if (theCapacity == 0)
	   {
		   reserve(1);
	   }
	   else
	   {
		   reserve(theCapacity * 2);
	   }
   }

   template<typename T>
   bool operator==(const Vector<T>& lhs, const Vector<T>& rhs)
   {
    
    if(lhs.size()!=rhs.size())
    {
        return false;
    }

	   for(int i = 0; i <lhs.size();i++)
       {
        if(lhs.at(i)!= rhs.at(i))
        {
            return false;
        }
       }
       return true;
   }

   template<typename T>
   bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs)
   {
    if(lhs.size()!=rhs.size())
    {
        return true;
    }

	    for(int i = 0; i <lhs.size();i++)
       {
        if(lhs.at(i)!= rhs.at(i))
        {
            return true;
        }
       }
       return true;
   }

   template<typename T>
   std::ostream& operator<<(std::ostream& os, const Vector<T>& v)
   {
    v.print(os);
    return os;
   }



#endif
