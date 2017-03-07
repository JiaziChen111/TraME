/*################################################################################
  ##
  ##   Copyright (C) 2015 - 2017 the TraME Team:
  ##      Alfred Galichon
  ##      Keith O'Hara
  ##      Simon Weber
  ##
  ##   This file is part of TraME.
  ##
  ##   TraME is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   TraME is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ##   You should have received a copy of the GNU General Public License
  ##   along with TraME. If not, see <http://www.gnu.org/licenses/>.
  ##
  ################################################################################*/

/*
 * darum for NTU_general
 *
 * Keith O'Hara
 * 08/16/2016
 *
 * This version:
 * 02/15/2017
 */

#ifndef _trame_darum_HPP
#define _trame_darum_HPP

// internal function
template<typename Ta>
bool darum_int(const dse<Ta>& market, arma::mat* mu_out, arma::vec* mu_x0_out, arma::vec* mu_0y_out, arma::mat* U_out, arma::mat* V_out, const double* tol_inp, const int* max_iter_inp);

// wrappers
template<typename Ta>
bool darum(const dse<Ta>& market, arma::mat& mu_out);

template<typename Ta>
bool darum(const dse<Ta>& market, arma::mat& mu_out, const double& tol_inp);

template<typename Ta>
bool darum(const dse<Ta>& market, arma::mat& mu_out, const int& max_iter_inp);

template<typename Ta>
bool darum(const dse<Ta>& market, arma::mat& mu_out, const double& tol_inp, const int& max_iter_inp);

template<typename Ta>
bool darum(const dse<Ta>& market, arma::mat& mu_out, arma::mat& U_out, arma::mat& V_out);

template<typename Ta>
bool darum(const dse<Ta>& market, arma::mat& mu_out, arma::vec& mu_x0_out, arma::vec& mu_0y_out, arma::mat& U_out, arma::mat& V_out, const double* tol_inp, const int* max_iter_inp);

#include "darum.tpp"

#endif