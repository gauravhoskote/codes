#pragma once


using namespace std;
template <class T>
class  Vector
{
public:
    
    typedef T * iterator;
    
    Vector();
    Vector(unsigned int size);
    Vector(unsigned int size, const T & initial);
    Vector(const Vector<T> & v);
    ~Vector();
    
    unsigned int capacity() const;
    unsigned int size() const;
    iterator begin();
    iterator end();
    
    T & operator[](unsigned int index);
    Vector<T> & operator=(const Vector<T> &);
    // Operator overloading
    Vector<T> operator+( Vector<T> & aso);
    Vector<T> operator*( Vector<T> & aso);
    Vector<T> operator-( Vector<T> & aso);
    Vector<T> operator/( Vector<T> & aso);
    void operator+=( Vector<T> & aso);
    void operator-=( Vector<T> & aso);
    void operator*=( Vector<T> & aso);
    void operator/=( Vector<T> & aso);
    
private:
    unsigned int my_sizex;
    unsigned int my_sizey;
    unsigned int my_capacity;
    T * buffer;
};


template<class T>
Vector<T> Vector<T>::operator+(Vector<T> & aso){
    if(my_sizey != aso.size()){
        Vector<T> v(0);
        return v;
    }else{
        Vector<T> v(aso.size());
        for(unsigned int i = 0; i < v.size(); i++){
            v[i] = (*(buffer+i)) + aso[i];
        }
        return v;
    }
}

template<class T>
Vector<T> Vector<T>::operator*(Vector<T> & aso){
    if(my_sizey != aso.size()){
        Vector<T> v(0);
        return v;
    }else{
        Vector<T> v(aso.size());
        for(unsigned int i = 0; i < v.size(); i++){
            v[i] = (*(buffer+i)) * aso[i];
        }
        return v;
    }
}

template<class T>
Vector<T> Vector<T>::operator-(Vector<T> & aso){
    if(my_sizey != aso.size()){
        Vector<T> v(0);
        return v;
    }else{
        Vector<T> v(aso.size());
        for(unsigned int i = 0; i < v.size(); i++){
            v[i] = (*(buffer+i)) - aso[i];
        }
        return v;
    }
}

template<class T>
Vector<T> Vector<T>::operator/(Vector<T> & aso){
    if(my_sizey != aso.size()){
        Vector<T> v(0);
        return v;
    }else{
        Vector<T> v(aso.size());
        for(unsigned int i = 0; i < v.size(); i++){
            v[i] = (*(buffer+i)) / aso[i];
        }
        return v;
    }
}

template<class T>
void Vector<T>::operator+=(Vector<T> & aso){
    if(my_sizey != aso.size()){
    }else{
        for(unsigned int i = 0; i < aso.size(); i++){
            (*(buffer+i)) = (*(buffer+i)) + aso[i];
        }
    }
}

template<class T>
void Vector<T>::operator-=(Vector<T> & aso){
    if(my_sizey != aso.size()){
    }else{
        for(unsigned int i = 0; i < aso.size(); i++){
            (*(buffer+i)) = (*(buffer+i)) - aso[i];
        }
    }
}

template<class T>
void Vector<T>::operator*=(Vector<T> & aso){
    if(my_sizey != aso.size()){
    }else{
        for(unsigned int i = 0; i < aso.size(); i++){
            (*(buffer+i)) = (*(buffer+i)) * aso[i];
        }
    }
}

template<class T>
void Vector<T>::operator/=(Vector<T> & aso){
    if(my_sizey != aso.size()){
    }else{
        for(unsigned int i = 0; i < aso.size(); i++){
            (*(buffer+i)) = (*(buffer+i)) / aso[i];
        }
    }
}

template<class T>
Vector<T>::Vector()
{
    my_capacity = 0;
    my_sizex = 0;
    my_sizey = 0;
    buffer = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T> & v)
{
    my_sizey = v.size();
    my_sizex = 1;
    my_capacity = v.size();
    buffer = new T[my_sizey];
    for (unsigned int i = 0; i < my_sizey; i++){
        buffer[i] = v.buffer[i];}
    
}

template<class T>
Vector<T>::Vector(unsigned int size)
{
    my_capacity = size;
    my_sizey = size;
    my_sizex = 1;
    buffer = new T[size];
}

template<class T>
Vector<T>::Vector(unsigned int size, const T & initial)
{
    my_sizey = size;
    my_sizex = 1;
    my_capacity = size;
    buffer = new T [size];
    for (unsigned int i = 0; i < size; i++)
        buffer[i] = initial;
    
}

template<class T>
Vector<T> & Vector<T>::operator = (const Vector<T> & v)
{
    delete[ ] buffer;
    my_sizey = v.my_sizey;
    my_sizex = 1;
    my_capacity = v.my_capacity;
    buffer = new T [my_sizey];
    for (unsigned int i = 0; i < my_sizey; i++)
        buffer[i] = v.buffer[i];
    return *this;
}

template<class T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return buffer;
}

template<class T>
typename Vector<T>::iterator Vector<T>::end()
{
    return buffer + size();
}
template<class T>
unsigned int Vector<T>::size()const
{
    return my_sizey;
}

template<class T>
T& Vector<T>::operator[](unsigned int index)
{
    return buffer[index];
}

template<class T>
Vector<T>::~Vector()
{
    delete[ ] buffer;
}



//new
////////////////////////////////////////////////////////////////////////////////

//Matrix class
template<class T>
class Matrix{
public:
    typedef T ** iterator;
    Matrix();
    Matrix(unsigned int sizex,unsigned int sizey);
    Matrix(unsigned int size, unsigned int sizey, const T & initial);
    Matrix(const Matrix<T> & v);
    Vector<T>& operator[](unsigned int index);
    unsigned int nrow() const;
    unsigned int ncol() const;
    unsigned int size() const;
    //Oper Over
    Matrix<T> operator+(const Matrix<T> & aso);
    Matrix<T> operator-(const Matrix<T> & aso);
    Matrix<T> operator*(const Matrix<T> & aso);
    Matrix<T> operator = (const Matrix<T> & aso);
    Matrix<T> operator/(const Matrix<T> & aso);
    void operator+=(const Matrix<T> & aso);
    void operator-=(const Matrix<T> & aso);
    void operator/=(const Matrix<T> & aso);
    void operator*=(const Matrix<T> & aso);
    
private:
    unsigned int my_sizex;
    unsigned int my_sizey;
    unsigned int my_capacity;
    Vector<T>* buffer;
};

template<class T>
Matrix<T>::Matrix(){
    my_sizex = 0;
    my_sizey = 0;
    my_capacity = 0;
    buffer =0;
}

template<class T>
Matrix<T>::Matrix(unsigned int sizex,unsigned int sizey){
    my_sizex = sizex;
    my_sizey = sizey;
    my_capacity = my_sizex * my_sizey;
    buffer = new Vector<T> [sizex];
    Vector<T> s(sizey);
    for(unsigned int i = 0; i < sizex; i++){
        buffer[i] = s;
    }
    
}

template<class T>
Matrix<T>::Matrix(unsigned int sizex,unsigned int sizey, const T & initial){
    my_sizex = sizex;
    my_sizey = sizey;
    my_capacity = my_sizex * my_sizey;
    buffer = new Vector<T> [sizex];
    for(unsigned int i = 0; i < sizex; i++){
        Vector<T> s(sizey);
        buffer[i] = s;
    }
    for(unsigned int i = 0; i < my_sizex; i++){
        for(unsigned int j = 0; j < my_sizey; j++){
            buffer[i][j] = initial;
        }
    }
}


template<class T>
Matrix<T>::Matrix(const Matrix<T> & v)
{
    my_sizey = v.ncol();
    my_sizex = v.nrow();
    my_capacity = my_sizex * my_sizey;
    buffer = new Vector<T> [v.nrow()];
    Vector<T> s(v.ncol());
    for(unsigned int i = 0; i < v.nrow(); i++){
        buffer[i] = s;
    }
    for(int i = 0; i < v.nrow(); i++){
        for(int j = 0; j < v.ncol(); j++){
            buffer[i][j] = v.buffer[i][j];
        }
    }
    
}



template<class T>
Vector<T>& Matrix<T>::operator[](unsigned int x )
{
    return buffer[x];
}



template<class T>
unsigned int Matrix<T>::size()const
{
    return my_capacity;
}

template<class T>
unsigned int Matrix<T>::nrow()const
{
    return my_sizex;
}

template<class T>
unsigned int Matrix<T>::ncol()const
{
    return my_sizey;
}


//Operator Overloading for Matrix

template<class T>
Matrix<T> Matrix<T>::operator = (const Matrix<T> & aso){
    delete buffer;
    buffer = new Vector<T> [aso.nrow()];
    Vector<T> s(aso.ncol());
    for(unsigned int i = 0; i < aso.nrow(); i++){
        buffer[i] = s;
    }
    my_sizex = aso.nrow();
    my_sizey = aso.ncol();
    my_capacity = my_sizex * my_sizey;
    for(unsigned int i = 0; i < aso.nrow(); i++){
        for(unsigned int j = 0; j < aso.ncol(); j++){
            buffer[i][j] = aso.buffer[i][j];
        }
    }
    return *this;
    
}


template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> & aso){
    if(my_sizey == aso.ncol() && my_sizex == aso.nrow()){
        Matrix<T> m(my_sizex,my_sizey);
        for(int i = 0; i < my_sizex; i++){
            for(int j = 0; j < my_sizey; j++){
                m[i][j] = buffer[i][j] + aso.buffer[i][j];
            }
        }
        return m;
    }else{
        Matrix<T>  m;
        return m;
    }
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> & aso){
    if(my_sizey == aso.nrow()){
        Matrix<T> m(my_sizex,aso.ncol(),0);
        for(int i = 0; i < m.nrow(); i++){
            for(int j = 0; j < m.ncol(); j++){
                m[i][j] = 0;
                for(int k = 0; k < my_sizey; k++){
                    m[i][j] = m[i][j] + (buffer[i][k] * aso.buffer[k][j]);
                }
            }
        }
        return m;
    }else{
        Matrix<T>  m;
        return m;
    }
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> & aso){
    if(my_sizey == aso.ncol() && my_sizex == aso.nrow()){
        Matrix<T> m(my_sizex,my_sizey);
        for(int i = 0; i < my_sizex; i++){
            for(int j = 0; j < my_sizey; j++){
                m[i][j] = buffer[i][j]-aso.buffer[i][j];
            }
        }
        return m;
    }else{
        Matrix<T>  m;
        return m;
    }
}

template<class T>
void Matrix<T>::operator+=(const Matrix<T> & aso){
    if(my_sizey == aso.ncol() && my_sizex == aso.nrow()){
        for(int i = 0; i < my_sizex; i++){
            for(int j = 0; j < my_sizey; j++){
                buffer[i][j] = buffer[i][j] + aso.buffer[i][j];
            }
        }
    }else{
        
    }
}

template<class T>
void Matrix<T>::operator/=(const Matrix<T> & aso){
    if(my_sizey == aso.ncol() && my_sizex == aso.nrow()){
        for(int i = 0; i < my_sizex; i++){
            for(int j = 0; j < my_sizey; j++){
                buffer[i][j] = buffer[i][j] / aso.buffer[i][j];
            }
        }
    }else{
        
    }
}


template<class T>
void Matrix<T>::operator-=(const Matrix<T> & aso){
    if(my_sizey == aso.ncol() && my_sizex == aso.nrow()){
        for(int i = 0; i < my_sizex; i++){
            for(int j = 0; j < my_sizey; j++){
                buffer[i][j] = buffer[i][j] - aso.buffer[i][j];
            }
        }
    }else{
        
    }
}



template<class T>
Matrix<T> Matrix<T>::operator/(const Matrix<T> & aso){
    if(my_sizey == aso.ncol() && my_sizex == aso.nrow()){
        Matrix<T> m(my_sizex,my_sizey);
        for(int i = 0; i < my_sizex; i++){
            for(int j = 0; j < my_sizey; j++){
                m[i][j] = buffer[i][j]/aso.buffer[i][j];
            }
        }
        return m;
    }else{
        Matrix<T>  m;
        return m;
    }
}


template<class T>
void Matrix<T>::operator*=(const Matrix<T> & aso){
    if(my_sizey == aso.nrow()){
        Matrix<T> m(my_sizex,aso.ncol(),0);
        for(int i = 0; i < m.nrow(); i++){
            for(int j = 0; j < m.ncol(); j++){
                m[i][j] = 0;
                for(int k = 0; k < my_sizey; k++){
                    m[i][j] = m[i][j] + (buffer[i][k] * aso.buffer[k][j]);
                }
            }
        }
        my_sizey = m.ncol();
        my_sizex = m.nrow();
        my_capacity = my_sizex * my_sizey;
        buffer = new Vector<T> [m.nrow()];
        Vector<T> s(m.ncol());
        for(unsigned int i = 0; i < m.nrow(); i++){
            buffer[i] = s;
        }
        for(int i = 0; i < m.nrow(); i++){
            for(int j = 0; j < m.ncol(); j++){
                buffer[i][j] = m.buffer[i][j];
            }
        }
    }else{
        
    }
}

