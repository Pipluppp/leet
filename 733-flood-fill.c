/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void fill(int **image, int imageSize, int *imageColSize, int r, int c, int old_color,
    int new_color){

    // If pixel outside of image
    if (r < 0 || r >= imageSize || c < 0 || c >= *imageColSize)
        return;

    if (image[r][c] != old_color)
        return;

    image[r][c] = new_color;

    fill(image, imageSize, imageColSize, r - 1, c, old_color, new_color);
    fill(image, imageSize, imageColSize, r + 1, c, old_color, new_color);
    fill(image, imageSize, imageColSize, r, c - 1, old_color, new_color);
    fill(image, imageSize, imageColSize, r, c + 1, old_color, new_color);
}


int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes){

    // Allocate memory for the image array (still don't understand why we need to)
    *returnSize = imageSize;
    *returnColumnSizes = malloc(sizeof(int) * imageSize);
    for (int i = 0; i < imageSize; i++)
        (*returnColumnSizes)[i] = imageColSize[i];

    // Trivial case
    if (color == image[sr][sc])
        return image;

    fill(image, imageSize, imageColSize, sr, sc, image[sr][sc], color);
    
    return image;
}