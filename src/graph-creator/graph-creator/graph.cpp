
#include <iostream>

#include "graph.h"

using std::cout;
using std::endl;

using std::vector;

namespace pln
{

/**
* Create an empty ordered map.
*/
graph::graph() :
    m_graph{ std::vector<std::vector<gid_t>>{} },
    m_gate_list{ std::vector<gate>{} }
{

}

void graph::insert_gate(gate const & new_gate)
{
    std::vector<gid_t> adj_vertices{};
    m_graph.push_back(adj_vertices);

    // map the new gate to its index
    // cout << "Inserting " << new_gate.get_name() << endl;
    m_gate_list.push_back(new_gate);
}

void graph::insert_edge(gid_t src, gid_t dest)
{
    if (src > m_graph.size())
    {
        perror("gate does not exist.");
        exit(1);
    }
    m_graph[src].push_back(dest);
}

void graph::set_heights(std::vector<gid_t> const & start_vertices)
{

}

void graph::print()
{
    cout << "ID\t(Name)\t(Type)\t\tAdjacent Gates(ID)" << endl;
    for (uint32_t i = 0; i < m_graph.size(); ++i)
    {
        gate cur_gate = m_gate_list[i];
        vector<gid_t> adj_gates = m_graph[i];
        cout << cur_gate.get_id() << '\t' <<
            '(' << cur_gate.get_name() << ')' << '\t' <<
            '(' << cur_gate.get_type() << ')' << "\t\t";
        if (adj_gates.size() == 2)
        {
            cout << adj_gates[0] << ", " << adj_gates[1];
        }
        else if (adj_gates.size() == 1)
        {
            cout << adj_gates[0];
        }
        cout << endl;
    }
}



}



