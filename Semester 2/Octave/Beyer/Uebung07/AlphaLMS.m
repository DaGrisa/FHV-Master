% Matlab code of Perceptron Learning Algorithm %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% % Copyright by Hans-Georg Beyer (HGB). For teaching use only! It is % not allowed to use this program without written permission by HGB %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% function [weightMatrix, weightMatrixChanges, errorHistory, iteration, weightMatrixFound, weightMatrixHistory] = AlphaLMS(x, d, alpha, max_iter = 1000)  % input x: made of K feature row vectors of dimension M  % input d = {-1,1}^K: column vector of dimension K  % output w: (normalized) weight vector the M+1st component is theta  % output n_w_changes: number of weight changes  % output n_iter: number of for-loop cycles  % output n_misclassified: dynamics of number of misclassified data  [rows, columns] =size(x);  weightMatrix = rand(columns+1, 1);   phi=x;   phi(:,columns+1)=ones(rows,1);  phi = phi';  weightMatrixChanges = 0;   weightMatrixFound = 0;  weightMatrixHistory = [];  errorHistory = [];  for iteration=1:max_iter    misclassificationCount = 0;     for k=1:rows      currentPhi = phi(:,k);      errorClass = d(k) - currentPhi*weightMatrix';      weightMatrix = weightMatrix + alpha * errorClass/sumsq(currentPhi)*currentPhi;            %if (sign( weightMatrix'*currentPhi) != d(k))         %w = w + d(k)*phi(k,:);      %  e_k = d(k) -xe(k,:)*w';      %  w = w + alpha * e_k/sumsq(xe(k,:))*xe(k,:)              %  weightMatrix = weightMatrix - alpha * currentPhi/norm(currentPhi)^2 * (weightMatrix'*currentPhi-d(k));      %  weightMatrixChanges++;       %  misclassificationCount = misclassificationCount + 1;      %end     end    weightMatrixHistory = [weightMatrixHistory; weightMatrix/norm(weightMatrix)];    iterationError = sumsq(d - phi'*weightMatrix);    errorHistory(iteration) = iterationError;        if (iterationError == 0)       weightMatrixFound = 1;      break;    end   end  weightMatrix = weightMatrix/norm(weightMatrix); end % function