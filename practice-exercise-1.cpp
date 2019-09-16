//Problem: You are given a stock of individual christmas lights. 10 red, 10 blue, 10 yellow.
//There are 2 models to choose from for manufacturing
//Model 1: 4 red lights, 2 blue lights, 2 yellow lights.
//Model 2: 1 of each color
//You can only make a max of 10 products for all models
//You can only make a max of 3 products per model
//Find the total number of products you can manufacture for this setup

#include <stdio.h>
#include <iostream>

//variable declaration
int stock_lights[3] = {10,10,10}; //array = {red, blue, yellow}
int model_1[3] = {4,2,2};
int model_2[3] = {1,1,1};
int total_product = 0; //find for this
int num_model_1 = 0;
int num_model_2 = 0;
int num_all_model = 0;
const int MAX_MODEL_1 = 3;
const int MAX_MODEL_2 = 3;
const int MAX_ALL_MODEL = 10;
bool is_red_stock_enough = true;
bool is_blue_stock_enough = true;
bool is_yellow_stock_enough = true;

//function prototypes
void createModel1();
void createModel2();
bool isEnough(int, int);

int main()
{
    std::cout << "Remainder of Red Lights: " << stock_lights[0] << std::endl;
    std::cout << "Remainder of Blue Lights: " << stock_lights[1] << std::endl;
    std::cout << "Remainder of Yellow Lights: " << stock_lights[2] << std::endl;
    //check if stock is enough for manufacturing model 1
    is_red_stock_enough = isEnough(stock_lights[0], model_1[0]);
    is_blue_stock_enough = isEnough(stock_lights[1], model_1[1]);
    is_yellow_stock_enough = isEnough(stock_lights[2], model_1[2]);
    //while stocks are enough for model 1, manufacture model 1
    while (is_red_stock_enough == true && is_blue_stock_enough == true && is_yellow_stock_enough == true && MAX_ALL_MODEL != num_all_model && MAX_MODEL_1 != num_model_1)
    {
        //create 1 model 1 item
        createModel1();
        std::cout << "model 1 created" << std::endl;
        std::cout << "Remainder of Red Lights: " << stock_lights[0] << std::endl;
        std::cout << "Remainder of Blue Lights: " << stock_lights[1] << std::endl;
        std::cout << "Remainder of Yellow Lights: " << stock_lights[2] << std::endl;
        //update status of stocks for model 1
        is_red_stock_enough = isEnough(stock_lights[0], model_1[0]);
        is_blue_stock_enough = isEnough(stock_lights[1], model_1[1]);
        is_yellow_stock_enough = isEnough(stock_lights[2], model_1[2]);
        
        
    }
    //while stocks are enough for model 2, manufacture model 2
    is_red_stock_enough = isEnough(stock_lights[0], model_2[0]);
    is_blue_stock_enough = isEnough(stock_lights[1], model_2[1]);
    is_yellow_stock_enough = isEnough(stock_lights[2], model_2[2]);
    while (is_red_stock_enough == true && is_blue_stock_enough == true && is_yellow_stock_enough == true && MAX_ALL_MODEL != num_all_model && MAX_MODEL_2 != num_model_2)
    {
        //create 1 model 2 item
        createModel2();
        std::cout << "model 2 created" << std::endl;
        std::cout << "Remainder of Red Lights: " << stock_lights[0] << std::endl;
        std::cout << "Remainder of Blue Lights: " << stock_lights[1] << std::endl;
        std::cout << "Remainder of Yellow Lights: " << stock_lights[2] << std::endl;
        //update status of stocks for model 2
        is_red_stock_enough = isEnough(stock_lights[0], model_2[0]);
        is_blue_stock_enough = isEnough(stock_lights[1], model_2[1]);
        is_yellow_stock_enough = isEnough(stock_lights[2], model_2[2]);
    }
    //if stock is not enough, break and print total

    std::cout << "Number of Model 1 Products: " << num_model_1 << std::endl;
    std::cout << "Number of Model 2 Products: " << num_model_2 << std::endl;

    std::cout << "\nTotal number of manufactured products: " << total_product << "\n" << std::endl;

    return 0;
}

void createModel1()
{
    for (int i = 0; i <= 3; i++)
    {
        stock_lights[i] = stock_lights[i] - model_1[i];
    }
    num_model_1++;
    num_all_model++;
    total_product++;
}

void createModel2()
{
    for (int i = 0; i <= 3; i++)
    {
        stock_lights[i] = stock_lights[i] - model_2[i];
    }
    num_model_2++;
    num_all_model++;
    total_product++;
}

bool isEnough(int stock, int product)
{
    if (stock >= product)
    {
        return true;
    }
    else
    {
        return false;
    }
}