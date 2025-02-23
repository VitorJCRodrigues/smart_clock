from PIL import Image
import sys
import os
import re

# Define the number of LEDs
NUM_LEDS = 25

def load_image_to_led_image(image_path):
    # Open the image
    try:
        img = Image.open(image_path)
    except FileNotFoundError:
        print(f"Error: The file '{image_path}' does not exist.")
        sys.exit(1)
    except Exception as e:
        print(f"Error: Unable to open the image. {e}")
        sys.exit(1)

    # Verify the image size
    if img.size != (5, 5):
        print("Error: The image must be exactly 5x5 pixels.")
        sys.exit(1)

    # Convert the image to RGB
    img = img.convert("RGB")

    # Define the pixel sequence used by the WS2812 devices
    x = []
    y = []
    for i in range(5):
        x.append([w for w in range(5)] if (i%2) else [4-w for w in range(5)])
        y.append([4-i for _ in range(5)])
    x = sum(x, [])
    y = sum(y, [])
            
    # Extract pixel data
    pixels = img.load()
    red = []
    green = []
    blue = []
    for k in range(25):
        r, g, b = pixels[x[k], y[k]]
        red.append(r)
        green.append(g)
        blue.append(b)

    return red, green, blue

def generate_c_struct(red, green, blue, struct_name):
    # Create the C struct for the image
    struct = f"Led_Image {struct_name} = {{\n"
    struct += "    .red = {" + ", ".join(map(str, red)) + "},\n"
    struct += "    .green = {" + ", ".join(map(str, green)) + "},\n"
    struct += "    .blue = {" + ", ".join(map(str, blue)) + "}\n"
    struct += "};\n"
    return struct

def update_or_append_header(new_struct, output_file, struct_name):
    # Read the existing file if it exists
    if os.path.exists(output_file):
        with open(output_file, "r") as f:
            content = f.read()

        # Pattern to find the existing struct
        struct_pattern = re.compile(rf"Led_Image {struct_name} = {{.*?}};\n", re.DOTALL)

        # Check if the struct already exists
        if struct_pattern.search(content):
            print(f"Struct '{struct_name}' found in '{output_file}', updating it.")
            # Replace the existing struct
            updated_content = struct_pattern.sub(new_struct, content)
        else:
            print(f"Struct '{struct_name}' not found in '{output_file}', appending it.")
            # Append the new struct at the end
            updated_content = content[:-17] + "\n" + new_struct + "\n#endif //ICONS_H"
    else:
        print(f"Header file '{output_file}' not found, creating a new one.")
        # Create a new header file with necessary includes
        updated_content = '//icons.h\n#ifndef ICONS_H\n#define ICONS_H\n\n#include "rgb_img.h"#include "rgb_img.h"\n\n' + new_struct

    # Write the updated content back to the file
    with open(output_file, "w") as f:
        f.write(updated_content)
    print(f"Header file '{output_file}' updated successfully.")

def main():
    # Check if the image path is provided as an argument
    if len(sys.argv) < 2:
        print("Usage: python png_parser.py <image_path> [output_header_file]")
        sys.exit(1)

    image_path = sys.argv[1]

    # If no output file is provided, default to 'icons.h'
    if len(sys.argv) == 2:
        output_file = "imgs/icons.h"
    else:
        output_file = sys.argv[2]

    # Extract the struct name from the input file name (without extension)
    struct_name = os.path.splitext(os.path.basename(image_path))[0]

    # Load the image and extract RGB values
    red, green, blue = load_image_to_led_image(image_path)

    # Generate the C struct
    new_struct = generate_c_struct(red, green, blue, struct_name)

    # Update or append the struct in the header file
    update_or_append_header(new_struct, output_file, struct_name)

if __name__ == "__main__":
    main()
