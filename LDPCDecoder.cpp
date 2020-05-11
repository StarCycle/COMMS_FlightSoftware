#include <LDPCDecoder.h>


const int LDPCDecoder::H1[2048] = {0, 63, 94, 178, 217, 363, 446, 448, 0, 1, 95, 179, 218, 364, 447, 449, 1, 2, 96, 180, 219, 365, 384, 450, 2, 3, 97, 181, 220, 366, 385, 451, 3, 4, 98, 182, 221, 367, 386, 452, 4, 5, 99, 183, 222, 368, 387, 453, 5, 6, 100, 184, 223, 369, 388, 454, 6, 7, 101, 185, 224, 370, 389, 455, 7, 8, 102, 186, 225, 371, 390, 456, 8, 9, 103, 187, 226, 372, 391, 457, 9, 10, 104, 188, 227, 373, 392, 458, 10, 11, 105, 189, 228, 374, 393, 459, 11, 12, 106, 190, 229, 375, 394, 460, 12, 13, 107, 191, 230, 376, 395, 461, 13, 14, 108, 128, 231, 377, 396, 462, 14, 15, 109, 129, 232, 378, 397, 463, 15, 16, 110, 130, 233, 379, 398, 464, 16, 17, 111, 131, 234, 380, 399, 465, 17, 18, 112, 132, 235, 381, 400, 466, 18, 19, 113, 133, 236, 382, 401, 467, 19, 20, 114, 134, 237, 383, 402, 468, 20, 21, 115, 135, 238, 320, 403, 469, 21, 22, 116, 136, 239, 321, 404, 470, 22, 23, 117, 137, 240, 322, 405, 471, 23, 24, 118, 138, 241, 323, 406, 472, 24, 25, 119, 139, 242, 324, 407, 473, 25, 26, 120, 140, 243, 325, 408, 474, 26, 27, 121, 141, 244, 326, 409, 475, 27, 28, 122, 142, 245, 327, 410, 476, 28, 29, 123, 143, 246, 328, 411, 477, 29, 30, 124, 144, 247, 329, 412, 478, 30, 31, 125, 145, 248, 330, 413, 479, 31, 32, 126, 146, 249, 331, 414, 480, 32, 33, 127, 147, 250, 332, 415, 481, 33, 34, 64, 148, 251, 333, 416, 482, 34, 35, 65, 149, 252, 334, 417, 483, 35, 36, 66, 150, 253, 335, 418, 484, 36, 37, 67, 151, 254, 336, 419, 485, 37, 38, 68, 152, 255, 337, 420, 486, 38, 39, 69, 153, 192, 338, 421, 487, 39, 40, 70, 154, 193, 339, 422, 488, 40, 41, 71, 155, 194, 340, 423, 489, 41, 42, 72, 156, 195, 341, 424, 490, 42, 43, 73, 157, 196, 342, 425, 491, 43, 44, 74, 158, 197, 343, 426, 492, 44, 45, 75, 159, 198, 344, 427, 493, 45, 46, 76, 160, 199, 345, 428, 494, 46, 47, 77, 161, 200, 346, 429, 495, 47, 48, 78, 162, 201, 347, 430, 496, 48, 49, 79, 163, 202, 348, 431, 497, 49, 50, 80, 164, 203, 349, 432, 498, 50, 51, 81, 165, 204, 350, 433, 499, 51, 52, 82, 166, 205, 351, 434, 500, 52, 53, 83, 167, 206, 352, 435, 501, 53, 54, 84, 168, 207, 353, 436, 502, 54, 55, 85, 169, 208, 354, 437, 503, 55, 56, 86, 170, 209, 355, 438, 504, 56, 57, 87, 171, 210, 356, 439, 505, 57, 58, 88, 172, 211, 357, 440, 506, 58, 59, 89, 173, 212, 358, 441, 507, 59, 60, 90, 174, 213, 359, 442, 508, 60, 61, 91, 175, 214, 360, 443, 509, 61, 62, 92, 176, 215, 361, 444, 510, 62, 63, 93, 177, 216, 362, 445, 511, 56, 64, 125, 178, 215, 256, 421, 474, 57, 65, 126, 179, 216, 257, 422, 475, 58, 66, 127, 180, 217, 258, 423, 476, 59, 64, 67, 181, 218, 259, 424, 477, 60, 65, 68, 182, 219, 260, 425, 478, 61, 66, 69, 183, 220, 261, 426, 479, 62, 67, 70, 184, 221, 262, 427, 480, 63, 68, 71, 185, 222, 263, 428, 481, 0, 69, 72, 186, 223, 264, 429, 482, 1, 70, 73, 187, 224, 265, 430, 483, 2, 71, 74, 188, 225, 266, 431, 484, 3, 72, 75, 189, 226, 267, 432, 485, 4, 73, 76, 190, 227, 268, 433, 486, 5, 74, 77, 191, 228, 269, 434, 487, 6, 75, 78, 128, 229, 270, 435, 488, 7, 76, 79, 129, 230, 271, 436, 489, 8, 77, 80, 130, 231, 272, 437, 490, 9, 78, 81, 131, 232, 273, 438, 491, 10, 79, 82, 132, 233, 274, 439, 492, 11, 80, 83, 133, 234, 275, 440, 493, 12, 81, 84, 134, 235, 276, 441, 494, 13, 82, 85, 135, 236, 277, 442, 495, 14, 83, 86, 136, 237, 278, 443, 496, 15, 84, 87, 137, 238, 279, 444, 497, 16, 85, 88, 138, 239, 280, 445, 498, 17, 86, 89, 139, 240, 281, 446, 499, 18, 87, 90, 140, 241, 282, 447, 500, 19, 88, 91, 141, 242, 283, 384, 501, 20, 89, 92, 142, 243, 284, 385, 502, 21, 90, 93, 143, 244, 285, 386, 503, 22, 91, 94, 144, 245, 286, 387, 504, 23, 92, 95, 145, 246, 287, 388, 505, 24, 93, 96, 146, 247, 288, 389, 506, 25, 94, 97, 147, 248, 289, 390, 507, 26, 95, 98, 148, 249, 290, 391, 508, 27, 96, 99, 149, 250, 291, 392, 509, 28, 97, 100, 150, 251, 292, 393, 510, 29, 98, 101, 151, 252, 293, 394, 511, 30, 99, 102, 152, 253, 294, 395, 448, 31, 100, 103, 153, 254, 295, 396, 449, 32, 101, 104, 154, 255, 296, 397, 450, 33, 102, 105, 155, 192, 297, 398, 451, 34, 103, 106, 156, 193, 298, 399, 452, 35, 104, 107, 157, 194, 299, 400, 453, 36, 105, 108, 158, 195, 300, 401, 454, 37, 106, 109, 159, 196, 301, 402, 455, 38, 107, 110, 160, 197, 302, 403, 456, 39, 108, 111, 161, 198, 303, 404, 457, 40, 109, 112, 162, 199, 304, 405, 458, 41, 110, 113, 163, 200, 305, 406, 459, 42, 111, 114, 164, 201, 306, 407, 460, 43, 112, 115, 165, 202, 307, 408, 461, 44, 113, 116, 166, 203, 308, 409, 462, 45, 114, 117, 167, 204, 309, 410, 463, 46, 115, 118, 168, 205, 310, 411, 464, 47, 116, 119, 169, 206, 311, 412, 465, 48, 117, 120, 170, 207, 312, 413, 466, 49, 118, 121, 171, 208, 313, 414, 467, 50, 119, 122, 172, 209, 314, 415, 468, 51, 120, 123, 173, 210, 315, 416, 469, 52, 121, 124, 174, 211, 316, 417, 470, 53, 122, 125, 175, 212, 317, 418, 471, 54, 123, 126, 176, 213, 318, 419, 472, 55, 124, 127, 177, 214, 319, 420, 473, 16, 64, 128, 183, 219, 312, 320, 491, 17, 65, 129, 184, 220, 313, 321, 492, 18, 66, 130, 185, 221, 314, 322, 493, 19, 67, 131, 186, 222, 315, 323, 494, 20, 68, 132, 187, 223, 316, 324, 495, 21, 69, 133, 188, 224, 317, 325, 496, 22, 70, 134, 189, 225, 318, 326, 497, 23, 71, 135, 190, 226, 319, 327, 498, 24, 72, 136, 191, 227, 256, 328, 499, 25, 73, 128, 137, 228, 257, 329, 500, 26, 74, 129, 138, 229, 258, 330, 501, 27, 75, 130, 139, 230, 259, 331, 502, 28, 76, 131, 140, 231, 260, 332, 503, 29, 77, 132, 141, 232, 261, 333, 504, 30, 78, 133, 142, 233, 262, 334, 505, 31, 79, 134, 143, 234, 263, 335, 506, 32, 80, 135, 144, 235, 264, 336, 507, 33, 81, 136, 145, 236, 265, 337, 508, 34, 82, 137, 146, 237, 266, 338, 509, 35, 83, 138, 147, 238, 267, 339, 510, 36, 84, 139, 148, 239, 268, 340, 511, 37, 85, 140, 149, 240, 269, 341, 448, 38, 86, 141, 150, 241, 270, 342, 449, 39, 87, 142, 151, 242, 271, 343, 450, 40, 88, 143, 152, 243, 272, 344, 451, 41, 89, 144, 153, 244, 273, 345, 452, 42, 90, 145, 154, 245, 274, 346, 453, 43, 91, 146, 155, 246, 275, 347, 454, 44, 92, 147, 156, 247, 276, 348, 455, 45, 93, 148, 157, 248, 277, 349, 456, 46, 94, 149, 158, 249, 278, 350, 457, 47, 95, 150, 159, 250, 279, 351, 458, 48, 96, 151, 160, 251, 280, 352, 459, 49, 97, 152, 161, 252, 281, 353, 460, 50, 98, 153, 162, 253, 282, 354, 461, 51, 99, 154, 163, 254, 283, 355, 462, 52, 100, 155, 164, 255, 284, 356, 463, 53, 101, 156, 165, 192, 285, 357, 464, 54, 102, 157, 166, 193, 286, 358, 465, 55, 103, 158, 167, 194, 287, 359, 466, 56, 104, 159, 168, 195, 288, 360, 467, 57, 105, 160, 169, 196, 289, 361, 468, 58, 106, 161, 170, 197, 290, 362, 469, 59, 107, 162, 171, 198, 291, 363, 470, 60, 108, 163, 172, 199, 292, 364, 471, 61, 109, 164, 173, 200, 293, 365, 472, 62, 110, 165, 174, 201, 294, 366, 473, 63, 111, 166, 175, 202, 295, 367, 474, 0, 112, 167, 176, 203, 296, 368, 475, 1, 113, 168, 177, 204, 297, 369, 476, 2, 114, 169, 178, 205, 298, 370, 477, 3, 115, 170, 179, 206, 299, 371, 478, 4, 116, 171, 180, 207, 300, 372, 479, 5, 117, 172, 181, 208, 301, 373, 480, 6, 118, 173, 182, 209, 302, 374, 481, 7, 119, 174, 183, 210, 303, 375, 482, 8, 120, 175, 184, 211, 304, 376, 483, 9, 121, 176, 185, 212, 305, 377, 484, 10, 122, 177, 186, 213, 306, 378, 485, 11, 123, 178, 187, 214, 307, 379, 486, 12, 124, 179, 188, 215, 308, 380, 487, 13, 125, 180, 189, 216, 309, 381, 488, 14, 126, 181, 190, 217, 310, 382, 489, 15, 127, 182, 191, 218, 311, 383, 490, 35, 120, 190, 192, 203, 314, 323, 384, 36, 121, 191, 193, 204, 315, 324, 385, 37, 122, 128, 194, 205, 316, 325, 386, 38, 123, 129, 195, 206, 317, 326, 387, 39, 124, 130, 196, 207, 318, 327, 388, 40, 125, 131, 197, 208, 319, 328, 389, 41, 126, 132, 198, 209, 256, 329, 390, 42, 127, 133, 199, 210, 257, 330, 391, 43, 64, 134, 200, 211, 258, 331, 392, 44, 65, 135, 201, 212, 259, 332, 393, 45, 66, 136, 202, 213, 260, 333, 394, 46, 67, 137, 203, 214, 261, 334, 395, 47, 68, 138, 204, 215, 262, 335, 396, 48, 69, 139, 205, 216, 263, 336, 397, 49, 70, 140, 206, 217, 264, 337, 398, 50, 71, 141, 207, 218, 265, 338, 399, 51, 72, 142, 208, 219, 266, 339, 400, 52, 73, 143, 209, 220, 267, 340, 401, 53, 74, 144, 210, 221, 268, 341, 402, 54, 75, 145, 211, 222, 269, 342, 403, 55, 76, 146, 212, 223, 270, 343, 404, 56, 77, 147, 213, 224, 271, 344, 405, 57, 78, 148, 214, 225, 272, 345, 406, 58, 79, 149, 215, 226, 273, 346, 407, 59, 80, 150, 216, 227, 274, 347, 408, 60, 81, 151, 217, 228, 275, 348, 409, 61, 82, 152, 218, 229, 276, 349, 410, 62, 83, 153, 219, 230, 277, 350, 411, 63, 84, 154, 220, 231, 278, 351, 412, 0, 85, 155, 221, 232, 279, 352, 413, 1, 86, 156, 222, 233, 280, 353, 414, 2, 87, 157, 223, 234, 281, 354, 415, 3, 88, 158, 224, 235, 282, 355, 416, 4, 89, 159, 225, 236, 283, 356, 417, 5, 90, 160, 226, 237, 284, 357, 418, 6, 91, 161, 227, 238, 285, 358, 419, 7, 92, 162, 228, 239, 286, 359, 420, 8, 93, 163, 229, 240, 287, 360, 421, 9, 94, 164, 230, 241, 288, 361, 422, 10, 95, 165, 231, 242, 289, 362, 423, 11, 96, 166, 232, 243, 290, 363, 424, 12, 97, 167, 233, 244, 291, 364, 425, 13, 98, 168, 234, 245, 292, 365, 426, 14, 99, 169, 235, 246, 293, 366, 427, 15, 100, 170, 236, 247, 294, 367, 428, 16, 101, 171, 237, 248, 295, 368, 429, 17, 102, 172, 238, 249, 296, 369, 430, 18, 103, 173, 239, 250, 297, 370, 431, 19, 104, 174, 240, 251, 298, 371, 432, 20, 105, 175, 241, 252, 299, 372, 433, 21, 106, 176, 242, 253, 300, 373, 434, 22, 107, 177, 243, 254, 301, 374, 435, 23, 108, 178, 244, 255, 302, 375, 436, 24, 109, 179, 192, 245, 303, 376, 437, 25, 110, 180, 193, 246, 304, 377, 438, 26, 111, 181, 194, 247, 305, 378, 439, 27, 112, 182, 195, 248, 306, 379, 440, 28, 113, 183, 196, 249, 307, 380, 441, 29, 114, 184, 197, 250, 308, 381, 442, 30, 115, 185, 198, 251, 309, 382, 443, 31, 116, 186, 199, 252, 310, 383, 444, 32, 117, 187, 200, 253, 311, 320, 445, 33, 118, 188, 201, 254, 312, 321, 446, 34, 119, 189, 202, 255, 313, 322, 447};
uint8_t LDPCDecoder::sn[64] = {0};
uint8_t LDPCDecoder::en[512] = {0};


bool LDPCDecoder::getParity(uint8_t input[]){
    for(int i = 0; i < 256; i++){
        BitArray::setBit(LDPCDecoder::sn, i, false);
    }

    for(int i = 0; i < 2048; i++){
        if( BitArray::getBit(input,LDPCDecoder::H1[i]) == 0x01 ){
            BitArray::xorBit(LDPCDecoder::sn, i/8);
        }
    }
    int sumSn = 0;
    for(int i = 0; i < 256; i++){
        sumSn = sumSn + BitArray::getBit(LDPCDecoder::sn,i);
    }
    if (sumSn == 0){
        return true;
    }
    else{
        return false;
    }
}

void LDPCDecoder::getScore(){
    for(int i = 0; i < 512; i++){
        LDPCDecoder::en[i] = 0;
    }
    for(int i = 0; i < 2048; i++){
        LDPCDecoder::en[LDPCDecoder::H1[i]] += BitArray::getBit(LDPCDecoder::sn, i/8);
    }
}

uint8_t MaxValue(uint8_t inputArray[], int size){
    uint8_t maxValue = 0;
    for( int i = 0; i < size; i++){
        if(inputArray[i] > maxValue){
            maxValue = inputArray[i];
        }
    }
    return maxValue;
}

bool LDPCDecoder::iterateBitflip(uint8_t input[]){
//    serial.println("Iteration!");
    if(LDPCDecoder::getParity(input)){
        return true;
    }else{
        LDPCDecoder::getScore();
        uint8_t maxVal = MaxValue(LDPCDecoder::en, 512);
//        serial.println("Sn Array:");
//        for(int i = 0; i < 256; i++){
//            serial.print(sn[i], DEC);
//            serial.print(" ");
//        }
//        serial.println();
//
//
//        serial.println("En Array:");
//        for(int i = 0; i < 512; i++){
//            serial.print(en[i], DEC);
//            serial.print(" ");
//        }
//        serial.println();

        for(int i = 0; i < 512; i++){
            if(LDPCDecoder::en[i] == maxVal){
//                serial.print("MaxVal: ");
//                serial.print(maxVal, DEC);
//                serial.print("  CHANGE: ");
//                serial.print(i,DEC);
//                serial.println();
                BitArray::xorBit(input,i);
                //break;
            }
        }
        return false;
    }
}

