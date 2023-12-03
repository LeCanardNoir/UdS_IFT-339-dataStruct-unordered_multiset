//
//  unordered_setImpl.h
//  unordered_multiset
//
//  AUteur : Jean Goulet
//  Copyleft 2017
//
//  Modifie par : Vincent Ducharme, Automne 2022
//
//  Devoir fait par
//     Coéquipier 1 :
//     Coéquipier 2 :

#ifndef unordered_multisetImpl_h
#define unordered_multisetImpl_h


///////////////////////////////////////////
// avancer et reculer un iterateur

template <typename TYPE,typename classe_de_dispersion>
void unordered_multiset<TYPE, classe_de_dispersion>::iterator::avancer()
{
    // TODO: 1 iterator::avancer()
    m_pos++;
    if (m_pos == (*m_alv)->end()) {
        m_alv++;
        m_pos = (*m_alv)->begin();
    }

}

template <typename TYPE,typename classe_de_dispersion>
void unordered_multiset<TYPE, classe_de_dispersion>::iterator::reculer()
{
    // TODO: 2 iterator::reculer()
    /*if (m_pos == (*m_alv)->end())
        m_pos = (*m_alv)[(*m_alv)->size() - 1];*/

    --m_pos;
    if (m_pos == (*m_alv)->rend()) {
        --m_alv;
        m_pos = (*m_alv)->rbegin();
    }
}

/////////////////////////////////////////////////////////////////////
// fonctions generatrices

template <typename TYPE,typename classe_de_dispersion>
typename unordered_multiset<TYPE,classe_de_dispersion>::iterator
unordered_multiset<TYPE, classe_de_dispersion>::insert(const TYPE& val)
{
    // TODO: 3 insert(const TYPE& val)
    typename unordered_multiset<TYPE,classe_de_dispersion>::iterator p;

    // Voir note de cours 13 page 14
    float N = (float)m_rep.size();
    float n = (float)m_size;
    float a = n / N;

    if (!(a < 1)) {
        rehash(N);
    }


    size_t alv = disperseur(val) % (m_rep.size() - 1);
    
    if (!m_rep[alv]) {
        m_rep[alv] = new list<TYPE>();
    }

    m_rep[alv]->push_back(val);

    m_size++;
    return p;
}

template <typename TYPE,typename classe_de_dispersion>
size_t unordered_multiset<TYPE, classe_de_dispersion>::erase(const TYPE& val)
{
    // TODO: 4 erase(const TYPE& val)
    size_t nb=0;
    return nb;
}

template <typename TYPE,typename classe_de_dispersion>
typename unordered_multiset<TYPE,classe_de_dispersion>::iterator
unordered_multiset<TYPE, classe_de_dispersion>::erase(typename unordered_multiset<TYPE, classe_de_dispersion>::iterator i)
{
    // TODO: 5 erase(typename unordered_multiset<TYPE, classe_de_dispersion>::iterator i)
    return i;
}

#endif // unordered_multisetImpl_h
