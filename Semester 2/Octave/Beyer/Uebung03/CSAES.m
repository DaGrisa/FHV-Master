function [fitnessHistory, sigmaHistory, fitnessParent, generationCount, functionEvaluationCount, fitnessHistoryFunctionEvaluation, sigmaNormHistory, y2History] = CSAES(yParent, sigmaParent, sigmaStop, offspringPopulationSize, parentPopulationSize, targetFunction, searchPath, searchPathConstant, attenuation, maxGenerations)