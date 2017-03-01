function[sigmaParent, generationCount, fitnessHistory, sigmaHistory, functionEvaluationCount, fitnessHistoryFunctionEvaluation] = MetaES(yParent, sigmaParent, sigmaChangeFactor, parentPopulationSize, offspringPopulationSize, isolationTime, maxGenerationCount, desiredFitness, targetFunction)  generationCount = 0;  functionEvaluationCount = 0;  fitnessHistory = [];  fitnessHistoryFunctionEvaluation = [];  sigmaHistory = [];  do    sigmaFirst = sigmaParent * sigmaChangeFactor;    sigmaSecond = sigmaParent / sigmaChangeFactor;        [fitnessFirst, yFirst, functionEvaluationCountFirst, fitnessHistoryFunctionEvaluationFirst] = InnerES(parentPopulationSize, offspringPopulationSize, isolationTime, sigmaFirst, yParent, targetFunction);    [fitnessSecond, ySecond, functionEvaluationCountSecond, fitnessHistoryFunctionEvaluationSecond] = InnerES(parentPopulationSize, offspringPopulationSize, isolationTime, sigmaSecond, yParent, targetFunction);        functionEvaluationCount += functionEvaluationCountFirst + functionEvaluationCountSecond;    fitnessHistoryFunctionEvaluation = [fitnessHistoryFunctionEvaluation ; fitnessHistoryFunctionEvaluationFirst ; fitnessHistoryFunctionEvaluationSecond];        if(fitnessFirst < fitnessSecond)      sigmaParent = sigmaFirst;      yParent = yFirst;      fitnessParent = fitnessFirst;    else      sigmaParent = sigmaSecond;      yParent = ySecond;      fitnessParent = fitnessSecond;    end        fitnessHistory = [fitnessHistory ; fitnessParent];    sigmaHistory = [sigmaHistory ; sigmaParent];    generationCount++;  until generationCount >= maxGenerationCount || fitnessParent <= desiredFitness;end