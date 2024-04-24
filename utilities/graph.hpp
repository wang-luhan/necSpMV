// This code was adapted from part of the code in
//  the GAP Benchmark Suite (https://github.com/sbeamer/gapbs)
//  by xulei (565610152@qq.com).
// Here is the copyright information of the GAP Benchmark Suite.

// Copyright (c) 2015, The Regents of the University of California (Regents).
// All Rights Reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. Neither the name of the Regents nor the
//    names of its contributors may be used to endorse or promote products
//    derived from this software without specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL REGENTS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once
#include <stdint.h>
#include "command_line.h"
#include "pvector.h"

template <typename NodeID_, typename WeightT_>
struct NodeWeight
{
  NodeID_ v;
  WeightT_ w;
  NodeWeight() {}
  NodeWeight(NodeID_ v) : v(v), w(1) {}
  NodeWeight(NodeID_ v, WeightT_ w) : v(v), w(w) {}

  bool operator<(const NodeWeight &rhs) const
  {
    return v == rhs.v ? w < rhs.w : v < rhs.v;
  }

  // doesn't check WeightT_s, needed to remove duplicate edges
  bool operator==(const NodeWeight &rhs) const
  {
    return v == rhs.v;
  }

  // doesn't check WeightT_s, needed to remove self edges
  bool operator==(const NodeID_ &rhs) const
  {
    return v == rhs;
  }

  operator NodeID_()
  {
    return v;
  }
};

template <typename NodeID_, typename WeightT_>
std::ostream &operator<<(std::ostream &os,
                         const NodeWeight<NodeID_, WeightT_> &nw)
{
  os << nw.v << " " << nw.w;
  return os;
}

template <typename NodeID_, typename WeightT_>
std::istream &operator>>(std::istream &is, NodeWeight<NodeID_, WeightT_> &nw)
{
  is >> nw.v >> nw.w;
  return is;
}

template <typename SrcT, typename DstT = SrcT>
struct EdgePair
{
  SrcT u;
  DstT v;

  EdgePair() {}

  EdgePair(SrcT u, DstT v) : u(u), v(v) {}

  bool operator<(const EdgePair &rhs) const
  {
    return u == rhs.u ? v < rhs.v : u < rhs.u;
  }

  bool operator==(const EdgePair &rhs) const
  {
    return (u == rhs.u) && (v == rhs.v);
  }
};

template <typename NodeID_ = uint64_t,
          typename DestID_ = NodeID_,
          bool MakeInverse = true>
class CSRGraph
{

private:
  bool directed_ = false;
  const bool is_pattern = std::is_same<NodeID_, DestID_>::value;
  uint64_t m_ = 0, n_ = 0;
  uint64_t num_nodes_ = 0;
  uint64_t num_edges_ = 0;

  NodeID_ *out_offsets_ = nullptr;
  DestID_ *out_destValues_ = nullptr;

  NodeID_ *in_offsets_ = nullptr;
  DestID_ *in_destValues_ = nullptr;
  bool own_flag_ = false;

public:
  CSRGraph() {}

  CSRGraph(uint64_t num_nodes, uint64_t num_edges, NodeID_ *out_offsets, DestID_ *out_destValues) : directed_(false), m_(num_nodes), n_(num_nodes), num_nodes_(num_nodes), num_edges_(num_edges), out_offsets_(out_offsets), out_destValues_(out_destValues)
  {
  }

  CSRGraph(uint64_t num_nodes, uint64_t num_edges, NodeID_ *out_offsets, DestID_ *out_destValues, bool own_flag) : directed_(false), m_(num_nodes), n_(num_nodes), num_nodes_(num_nodes), num_edges_(num_edges), out_offsets_(out_offsets), out_destValues_(out_destValues), own_flag_(own_flag)
  {
  }

  CSRGraph(uint64_t num_nodes, uint64_t num_edges, NodeID_ *out_offsets, DestID_ *out_destValues, NodeID_ *in_offsets, DestID_ *in_destValues) : directed_(true), m_(num_nodes), n_(num_nodes), num_nodes_(num_nodes), num_edges_(num_edges), out_offsets_(out_offsets), out_destValues_(out_destValues), in_offsets_(in_offsets), in_destValues_(in_destValues)
  {
  }

    CSRGraph(uint64_t num_nodes, uint64_t num_edges, NodeID_ *out_offsets, DestID_ *out_destValues, NodeID_ *in_offsets, DestID_ *in_destValues,  bool own_flag) : directed_(true), m_(num_nodes), n_(num_nodes), num_nodes_(num_nodes), num_edges_(num_edges), out_offsets_(out_offsets), out_destValues_(out_destValues), in_offsets_(in_offsets), in_destValues_(in_destValues), own_flag_(own_flag)
  {
  }

  ~CSRGraph()
  {
    if (own_flag_)
    {
      if (nullptr != out_offsets_)
      {
        delete[] out_offsets_;
      }

      if (nullptr != out_destValues_)
      {
        delete[] out_destValues_;
      }

      if (nullptr != in_offsets_)
      {
        delete[] in_offsets_;
      }

      if (nullptr != in_destValues_)
      {
        delete[] in_destValues_;
      }
    }
  }

  void ShowGraph() const
  {
    for (NodeID_ i = 0; i < num_nodes_; i++)
    {
      std::cout << "INDEX: ";
      for (NodeID_ j = 0; j < (out_offsets_[i + 1] - out_offsets_[i]); j++)
      {
        std::cout << static_cast<NodeID_>(*(out_destValues_ + out_offsets_[i] + j)) << " ";
      }
      std::cout << std::endl;
    }
  }

  bool directed() const { return directed_; }
  uint64_t num_nodes() const { return num_nodes_; }
  uint64_t num_edges() const { return num_edges_; }
  NodeID_ *out_offsets() const { return out_offsets_; }
  DestID_ *out_destValues() const { return out_destValues_; }
  NodeID_ *in_offsets() const { return in_offsets_; }
  DestID_ *in_destValues() const { return in_destValues_; }
};
