function [fitnessHistory, sigmaHistory, fitnessParent, generationCount, functionEvaluationCount, fitnessHistoryFunctionEvaluation] = RecombinationSelfAdaptionES(yParent, sigmaParent, sigmaStop, offspringPopulationSize, parentPopulationSize, tau, targetFunction, maxGenerations, desiredFitness)  % initialization  dimensions = size(yParent, 1);    fitnessHistory = [feval(targetFunction, yParent)];  fitnessHistoryFunctionEvaluation = fitnessHistory;  yHistory = [yParent];  sigmaHistory = [sigmaParent];    generationCount = 0;  functionEvaluationCount = 1;    randn("state", 7); % random settings only valid in same scope    do    % empty pools    fitnessPool = [];    childrenPool = [];        % generate offspring    for i = 1:offspringPopulationSize      xi = e^(tau*randn(1));      sigmaLambda = sigmaParent * xi;      child.sigma = sigmaLambda;            mutation = randn(dimensions, 1);      yLambda = yParent + mutation * sigmaLambda;      child.y = yLambda;            childrenPool = [childrenPool ; child];            fitnessLambda = feval(targetFunction, yLambda);      functionEvaluationCount++;      fitnessHistoryFunctionEvaluation = [fitnessHistoryFunctionEvaluation ; fitnessLambda];      fitnessPool = [fitnessPool ; fitnessLambda];    end            % recombine best individuals    sigmaPool = [];    yPool = [];        for i = 1:parentPopulationSize      % choose best child      minFitness = min(fitnessPool);      indexBestChild = find(fitnessPool == minFitness);            % set best value to infinite      fitnessPool(indexBestChild) = inf;            % save values into pools      sigmaChild = childrenPool(indexBestChild).sigma;      sigmaPool = [sigmaPool ; sigmaChild];      yChild = childrenPool(indexBestChild).y;      yPool = [yPool ; yChild'];    end        % set new parent values    sigmaParent = MeanCalc(sigmaPool);    sigmaHistory = [sigmaHistory ; sigmaParent];        yParent = MeanCalc(yPool)';    if(size(yParent,1) != dimensions)      size(yParent,1)      error("yParent wrong dimensions!");    end    yHistory = [yHistory ; yParent];        fitnessParent = feval(targetFunction, yParent);    fitnessHistory = [fitnessHistory ; fitnessParent];            generationCount++;  until sigmaParent < sigmaStop || generationCount == maxGenerations || fitnessParent <= desiredFitness;end