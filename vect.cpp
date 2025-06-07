#include <iostream>

class MyVector {
	private: 
		size_t m_size;
		size_t m_capacity;
		int* m_data;
	public:
		MyVector() {
			m_size = 0;
			m_capacity = 0;
			m_data = NULL;
		}
		MyVector(size_t size) {
			m_capacity = size * 2;
			m_size = size;
			m_data = new int[m_capacity];
			for (int i = 0; i < size; ++i) {
				m_data[i] = 0;
			}
		} 
		MyVector(size_t size, int val) {
			m_size = size;
			m_capacity = size * 2;			
			m_data = new int[m_capacity];
			for (int i = 0; i < m_size; ++i) {
				m_data[i] = val;
			}
		}
		~MyVector() {
			delete []m_data;
			m_size = 0;
                        m_capacity = 0;
                        m_data = NULL;
		}
		size_t sizevc() {
			return m_size;
		}
		size_t capacvc() {
			return m_capacity;
		}
		void pushback(int val) {
			if (m_size == m_capacity) {
				if (m_capacity == 0) {
                                	m_capacity = 1;
                     		} else {
	                                m_capacity *= 2;
			 	}
				int* tmp = new int[m_capacity]; 
                        	for (int i = 0; i < m_size; ++i) {
                                	tmp[i] = m_data[i];
                       		}
                       		delete []m_data;
                        	m_data = tmp;
			}
			m_data[m_size++] = val;	
		}

		void popback() {
     			if (m_size > 0) {
            			m_size--;
        		}
   		}
		void resize(size_t count) {
			if (count >= m_capacity) {
				m_capacity = count;
				int* tmp = new int[m_capacity];
                                for (int i = 0; i < m_size; ++i) {
                                        tmp[i] = m_data[i];
                                }		
				delete []m_data;
                                m_data = tmp;		
			}
			if (count > m_size) {
           	 		for (size_t i = m_size; i < count; ++i) {
                			m_data[i] = 0;
            			}
        		}
        		m_size = count;
		}
		void clear() {
     			m_size = 0;
    		}	
		void print() {
  	     		for (int i = 0; i < m_size; ++i) {
        			std::cout << m_data[i];
        			if (i + 1 < m_size) {
            				std::cout << ", ";
    				}
			}
			std::cout << "\n";
		}
};


int main() {
	MyVector vec;
	vec.pushback(5);
	vec.pushback(10);	
	vec.pushback(15);
	vec.pushback(20);
	vec.print();

	std::cout << "The size of vector is " << vec.sizevc() << std::endl;

	vec.popback();
	vec.popback();
	vec.print();

	vec.resize(10);
	vec.print();
	
	vec.clear();
	vec.print();

	return 0;
}
