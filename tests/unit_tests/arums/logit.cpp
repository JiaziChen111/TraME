/*################################################################################
  ##
  ##   Copyright (C) 2015 - 2017 the TraME Team:
  ##      Alfred Galichon
  ##      Keith O'Hara
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
 * logit class test
 *
 * Keith O'Hara
 * 05/17/2016
 *
 * This version:
 * 07/03/2017
 */

#include "trame.hpp"

int main()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    //
    // inputs:
    arma::mat U(2,3);
    U  << 1.6 << 3.2 << 1.1 << arma::endr
       << 2.9 << 1.0 << 3.1 << arma::endr;
    
    arma::mat mu(2,3);
    mu << 1.0 << 3.0 << 1.0 << arma::endr
       << 2.0 << 1.0 << 3.0 << arma::endr;

    const int nbX = U.n_rows;
    const int nbY = U.n_cols;
    
    arma::vec n = arma::sum(mu,1);
    //
    // results
    printf("\n*===================   Start of arums::logit Test   ===================*\n");
    printf("\n");
    arma::cout << "\nU: \n" << U << arma::endl;
    arma::cout << "mu: \n" << mu << arma::endl;

    // builds

    trame::arums::logit logits(nbX,nbY);
    trame::arums::logit logits2(nbX,nbY,1.0,true);

    logits.build(nbX,nbY);
    logits.build(nbX,nbY,1.0,true);

    // G

    arma::mat mu_sol;
    logits.U = U;

    logits.G(n);
    logits.G(n,U,mu_sol);

    // Gstar

    arma::mat U_sol;

    logits.Gstar(n);
    logits.Gstar(n,mu,U_sol);

    // Gbar

    arma::mat mu_bar(2,3);
    mu_bar.fill(2);
    
    arma::mat U_bar_out, mu_bar_out;
    
    logits.Gbar(U,mu_bar,n,U_bar_out,mu_bar_out);

    // D2G

    arma::mat H;

    logits.D2G(n,true);
    logits.D2G(H,n,true);
    logits.D2G(n,U,true);
    logits.D2G(H,n,U,true);

    // simul
    trame::arums::empirical logit_sim(nbX,nbY);
    const int sim_seed = 1777, n_draws = 1000;
    logits.simul(logit_sim, n_draws, sim_seed);

    //
    printf("\n*===================   end of arums::logit test   ===================*\n");
    printf("\n");
    //
    end = std::chrono::system_clock::now();
        
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
    //
    return 0;
}
