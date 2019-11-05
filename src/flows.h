#pragma once

#include <memory>
#include <vector>
#include <algorithm> // std::fill, std::reverse
#include <iostream>
#include <fstream>

#include <Rcpp.h>
// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::depends(RcppParallel,RcppThread)]]
#include <RcppThread.h>
#include <RcppParallel.h>

#include "pathfinders.h"

class DGraph;
class PathFinder;

//----------------------------
//----- functions in flows.cpp
//----------------------------

void rcpp_flows_aggregate_par (const Rcpp::DataFrame graph,
        const Rcpp::DataFrame vert_map_in,
        Rcpp::IntegerVector fromi,
        Rcpp::IntegerVector toi_in,
        Rcpp::NumericMatrix flows,
        const double tol,
        const std::string dirtxt,
        const std::string heap_type);

Rcpp::NumericVector rcpp_aggregate_files (const Rcpp::CharacterVector file_names,
        const int len);

Rcpp::NumericVector rcpp_flows_disperse (const Rcpp::DataFrame graph,
        const Rcpp::DataFrame vert_map_in,
        Rcpp::IntegerVector fromi,
        Rcpp::NumericVector kfrom,
        Rcpp::NumericVector flows,
        const double &tol,
        std::string heap_type);

Rcpp::NumericVector rcpp_flows_disperse_par (const Rcpp::DataFrame graph,
        const Rcpp::DataFrame vert_map_in,
        Rcpp::IntegerVector fromi,
        Rcpp::NumericVector k,
        Rcpp::NumericVector flows,
        const double &tol,
        std::string heap_type);

void rcpp_flows_si (const Rcpp::DataFrame graph,
        const Rcpp::DataFrame vert_map_in,
        Rcpp::IntegerVector fromi,
        Rcpp::IntegerVector toi_in,
        Rcpp::NumericVector kvec,
        Rcpp::NumericVector dens_from,
        Rcpp::NumericVector dens_to,
        const double tol,
        const std::string dirtxt,
        const std::string heap_type);
