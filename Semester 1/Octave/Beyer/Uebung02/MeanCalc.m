function[result] = MeanCalc(values)  dimensions = size(values, 1);  if(dimensions == 1)    result = values;  else    dimensionsVector = size(values, 2);    for j = 1:dimensionsVector      intermediateValue = 0;      for i = 1:dimensions        intermediateValue += values(i, j);      end      result(j) = intermediateValue/dimensions;    end  endend