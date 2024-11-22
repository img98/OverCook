// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/Recipe.h"
#include "Data/FoodItem.h"
#include "Data/Ingredient.h"

bool URecipe::Compare(TMap<UFoodItem*, FIngredient> InIngredient)
{
    if (InIngredient.GetMaxIndex() == Ingredient.GetMaxIndex())
    {      
        for (auto Pair : Ingredient.Array())
        {
            FIngredient* InValue = InIngredient.Find(Pair.Key);
            if (InValue)
            {
                if (!CompareState(*InValue, (Pair.Value)))
                {
                    return false;
                }
            }
            else
            {
                return false;
            }                
        }
        return true;
    }
    return false;
}

bool URecipe::CompareState(FIngredient A, FIngredient B)
{
    if (A.State == B.State && A.Amount == B.Amount)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

