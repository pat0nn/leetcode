import matplotlib.pyplot as plt


def visualize(height):
    
    n = len(height)
    plt.bar(range(n), height, color='blue', alpha=0.6, label='Height of Columns')
    plt.show()

# Example usage
height = [4,3,5,5,9,2,8,4,7,2,3,8,3,5,4,7,9]

visualize(height)
