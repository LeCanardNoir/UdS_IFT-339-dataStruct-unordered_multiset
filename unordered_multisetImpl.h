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
    ++m_pos;
    if (m_pos == (*m_alv)->end()) {
        ++m_alv;
        while (*m_alv == nullptr) ++m_alv;
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
    if (m_pos == (*m_alv)->end()) {
        --m_alv;
        while (*m_alv == nullptr) --m_alv;
            m_pos = (*m_alv)->end();
            --m_pos;
    }
}

/////////////////////////////////////////////////////////////////////
// fonctions generatrices

template <typename TYPE,typename classe_de_dispersion>
typename unordered_multiset<TYPE,classe_de_dispersion>::iterator
unordered_multiset<TYPE, classe_de_dispersion>::insert(const TYPE& val)
{
    // TODO: 3 insert(const TYPE& val)
    typename unordered_multiset<TYPE, classe_de_dispersion>::iterator p;

    size_t alv = disperseur(val) % (m_rep.size() - 1);
    
    if (!m_rep[alv]) {
        m_rep[alv] = new list<TYPE>();
    }

    m_rep[alv]->push_back(val);
    m_size++;

    p = unordered_multiset<TYPE, classe_de_dispersion>::iterator(m_rep.end(), m_rep.back()->end());

    // Voir note de cours 13 page 14
    float N = (float)m_rep.size();
    float n = (float)m_size;
    float a = n / N;

    if (!(a < 1)) {
        rehash(N);
        p = unordered_multiset<TYPE, classe_de_dispersion>::iterator(m_rep.end(), m_rep.back()->end());
    }


    return p;
}

template <typename TYPE,typename classe_de_dispersion>
size_t unordered_multiset<TYPE, classe_de_dispersion>::erase(const TYPE& val)
{
    // TODO: 4 erase(const TYPE& val)
    size_t nb=0;

    size_t alv = disperseur(val) % (m_rep.size() - 1);
    if (!m_rep[alv]) return nb;

    nb = count(val);
    size_t count = 0;
    size_t currentPos = 0;

    //auto i_avl = m_rep.begin() + alv;
    //typename unordered_multiset<TYPE, classe_de_dispersion>::iterator it(i_avl, m_rep[alv]->begin());
    //size_t size = (*i_avl)->size();
    typename unordered_multiset<TYPE, classe_de_dispersion>::iterator it;

    while (count < nb) {
        alv = disperseur(val) % (m_rep.size() - 1);
        auto i_avl = m_rep.begin() + alv;
        if (m_rep[alv]) {
            it = iterator(i_avl, std::find(m_rep[alv]->begin(), m_rep[alv]->end(), val));
        }           
        else {
            it = iterator(m_rep.end(), m_rep.back()->end());
            break;
        }
        if (val == *it) {
            erase(it);
            ++count;
        }
        else {
            break;
        }
        ++currentPos;
        //++it;
    }

    

    return nb;
}

template <typename TYPE,typename classe_de_dispersion>
typename unordered_multiset<TYPE,classe_de_dispersion>::iterator
unordered_multiset<TYPE, classe_de_dispersion>::erase(typename unordered_multiset<TYPE, classe_de_dispersion>::iterator i)
{
    // TODO: 5 erase(typename unordered_multiset<TYPE, classe_de_dispersion>::iterator i)
    if (i == end()) return end();
    auto alv = i.m_alv;
    auto pos = i.m_pos;

    if (!(*alv) || pos == (*alv)->end()) return end();
    
    /*delete (*alv);
    (*alv) = nullptr;*/
    pos = (*alv)->erase(pos);
    if ((*alv)->empty()) {
        m_rep.erase(alv);
    }
    --m_size;

    i = iterator(--m_rep.end(), m_rep.back()->end());
    float N = (float)m_rep.size();
    float n = (float)m_size;
    float a = n / N;

    if (!(1 < a)) {
        rehash(n);
        i = unordered_multiset<TYPE, classe_de_dispersion>::iterator(m_rep.end(), m_rep.back()->end());
    }
    return i;
}

#endif // unordered_multisetImpl_h
