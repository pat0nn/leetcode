import matplotlib.pyplot as plt


def visualize(height):
    
    n = len(height)
    plt.bar(range(n), height, color='blue', alpha=0.6, label='Height of Columns')
    plt.xlabel('Index')
    plt.ylabel('Height')
    plt.title('Trapping Rain Water Problem')
    plt.twinx()
    plt.ylabel('Water Trapped')
    plt.grid()
    plt.legend(loc='upper left')
    plt.show()

# Example usage
height = [0,1,0,2,1,0,1,3,2,1,2,1]

visualize(height)
