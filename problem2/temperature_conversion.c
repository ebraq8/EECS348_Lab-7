#include <stdio.h>

// Conversion functions
float celsius_to_fahrenheit(float celsius) {
    return (9.0/5.0) * celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0/9.0) * (fahrenheit - 32);
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// Categorization function
void categorize_temperature(float celsius) {
    if (celsius < 0)
        printf("Category: Freezing - Advisory: Wear heavy winter clothes.\n");
    else if (celsius <= 10)
        printf("Category: Cold - Advisory: Wear a jacket.\n");
    else if (celsius <= 25)
        printf("Category: Comfortable - Advisory: Enjoy the pleasant weather!\n");
    else if (celsius <= 35)
        printf("Category: Hot - Advisory: Stay hydrated!\n");
    else
        printf("Category: Extreme Heat - Advisory: Stay indoors or seek shade!\n");
}

// Main program
int main() {
    float temp, converted_temp, temp_celsius;
    int input_scale, target_scale;

    printf("Enter temperature value: ");
    scanf("%f", &temp);

    printf("Enter input scale (1: Celsius, 2: Fahrenheit, 3: Kelvin): ");
    scanf("%d", &input_scale);

    printf("Enter target scale (1: Celsius, 2: Fahrenheit, 3: Kelvin): ");
    scanf("%d", &target_scale);

    if(input_scale == target_scale) {
        printf("Invalid conversion: source and target scales are the same.\n");
        return 1;
    }

    // Convert input temperature to Celsius first
    if(input_scale == 1) temp_celsius = temp;
    else if(input_scale == 2) temp_celsius = fahrenheit_to_celsius(temp);
    else if(input_scale == 3) {
        if(temp < 0) {
            printf("Invalid temperature: Kelvin cannot be negative.\n");
            return 1;
        }
        temp_celsius = kelvin_to_celsius(temp);
    }
    else {
        printf("Invalid input scale selected.\n");
        return 1;
    }

    // Now convert Celsius to target scale
    if(target_scale == 1) converted_temp = temp_celsius;
    else if(target_scale == 2) converted_temp = celsius_to_fahrenheit(temp_celsius);
    else if(target_scale == 3) converted_temp = celsius_to_kelvin(temp_celsius);
    else {
        printf("Invalid target scale selected.\n");
        return 1;
    }

    printf("Converted temperature: %.2f\n", converted_temp);
    categorize_temperature(temp_celsius);

    return 0;
}
