% Aufgabe 12 %%%%%%%%%%%%%%set (0, "defaultaxesfontname", "Helvetica")set (0, "defaultaxesfontsize", 14)set (0, "defaulttextfontname", "Helvetica")set (0, "defaulttextfontsize", 14) dimensions = 10;yParent = ones(dimensions, 1);sigmaParent = 1;sigmaStop = 10^(-5);offspringPopulationSize = 10;parentPopulationSize = 3;searchPath = ones(dimensions, 1);searchPathConstant = 1/sqrt(dimensions);attenuation = sqrt(dimensions);maxGenerations = 2000;desiredFitness = 0;%10^(-10);tau = (2*dimensions)^(-1/2);evolutionPath = ones(dimensions, 1);evolutionPathConstant = 1/sqrt(dimensions);covarianceConstant = 2/(dimensions + sqrt(2))^2;covarianceMatrix = eye(dimensions, dimensions);functions = {'HappyCat';'HGBat'};for f = 1:size(functions)  functionName = functions{f}  [fitnessHistoryCMSA, sigmaHistoryCMSA, fitnessParent, generationCount, functionEvaluationCount, fitnessHistoryFunctionEvaluation, sigmaNormHistoryCMSA, yHistory] = CMSAES(yParent, sigmaParent, sigmaStop, offspringPopulationSize, parentPopulationSize, functionName, searchPath, searchPathConstant, attenuation, maxGenerations, covarianceConstant, evolutionPathConstant, evolutionPath, covarianceMatrix);  plot = figure(f);  semilogy(fitnessHistoryCMSA,'r-');  hold on  semilogy(sigmaHistoryCMSA,'b-');  legend("CMSA Fitness", "CMSA Sigma");  title(strcat("Exercise 12 - CMSA-ES - Fitness Dynamics - ", functionName));  ylabel("Fitness / Sigma Value");  xlabel("Generation number");    print(plot, strcat("Exercise 12 - CMSA-ES - Fitness Dynamics - ", functionName, ".png"), "-dpng");end