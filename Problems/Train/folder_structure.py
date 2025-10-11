"""
    Problem: get top 10 files based on size from the folder structure using get_size and list_contents. get_size => size for files and -1 for folders
    Problem 2: get top 10 directories in terms of size from the root directory
"""

import heapq
from collections import deque

folder_structure = {
    "documents": {
        "resume.pdf": 2048,
        "cover_letter.docx": 1024,
        "projects": {
            "project1": {
                "main.py": 512,
                "config.json": 256,
                "data": {
                    "input.csv": 4096,
                    "output.txt": 128
                }
            },
            "project2": {
                "app.js": 1536,
                "package.json": 512,
                "node_modules": {
                    "express": {
                        "index.js": 8192,
                        "package.json": 256
                    },
                    "lodash": {
                        "lodash.js": 16384
                    }
                }
            }
        }
    },
    "photos": {
        "vacation": {
            "beach.jpg": 3072,
            "sunset.jpg": 2560
        },
        "family": {
            "birthday.png": 1800,
            "christmas.jpg": 2200
        },
        "profile.jpg": 1024
    },
    "music": {
        "rock": {
            "song1.mp3": 5120,
            "song2.mp3": 4800
        },
        "jazz": {
            "album1": {
                "track1.mp3": 6144,
                "track2.mp3": 5888
            }
        }
    },
    "readme.txt": 512
}

def get_size(structure, path):
    """
    Get the size of a file or folder in the structure.
    
    Args:
        structure (dict): The folder structure
        path (str): Path to the file/folder (e.g., "documents/projects/project1/main.py")
    
    Returns:
        int: Size of file if it's a file, -1 if it's a folder, None if path doesn't exist
    """
    # Split the path into components
    if path == "":
        # Root folder
        return -1
    
    path_parts = path.split("/")
    current = structure
    
    # Navigate through the path
    for part in path_parts:
        if isinstance(current, dict) and part in current:
            current = current[part]
        else:
            return None  # Path doesn't exist
    
    # Check if it's a file (integer) or folder (dictionary)
    if isinstance(current, int):
        return current  # It's a file, return its size
    elif isinstance(current, dict):
        return -1  # It's a folder
    else:
        return None  # Unexpected type

def list_contents(structure, path=""):
    """
    List all contents in a given folder path.
    
    Args:
        structure (dict): The folder structure
        path (str): Path to the folder (empty string for root)
    
    Returns:
        list: List of items in the folder, or None if path doesn't exist
    """
    if path == "":
        current = structure
    else:
        path_parts = path.split("/")
        current = structure
        
        for part in path_parts:
            if isinstance(current, dict) and part in current:
                current = current[part]
            else:
                return None  # Path doesn't exist
    
    if isinstance(current, dict):
        return list(current.keys())
    else:
        return None  # Not a folder
    

def recursive_solution(path=""):
    maxheap = []

    def recursive_func(path=""):
        contents = list_contents(folder_structure, path)

        if not contents:
            return
        
        for file in contents:
            full_path = f"{path}/{file}" if path else file

            if get_size(folder_structure, full_path) == -1:
                recursive_func(full_path)
            else:
                heapq.heappush(maxheap, (-get_size(folder_structure, full_path), full_path))


    recursive_func(path)

    for _ in range(min(10, len(maxheap))):
        element = heapq.heappop(maxheap)
        print(element)

def iterative_solution_with_queue(path=""):
    maxheap = []
    q = deque()
    q.append(path)

    while q:
        curr = q.popleft()

        for el in list_contents(folder_structure, curr):
            full_path = f"{curr}/{el}" if curr else el
            size = get_size(folder_structure, full_path)

            if size == -1:
                q.append(full_path)
            else:
                heapq.heappush(maxheap, (-size, full_path))

    for _ in range(min(10, len(maxheap))):
        el = heapq.heappop(maxheap)
        print(el)

def iterative_solution_with_stack(path=""):
    stack = []
    maxheap = []

    stack.append(path)

    while stack:
        curr = stack.pop()

        for el in list_contents(folder_structure, curr):
            full_path = f"{curr}/{el}" if curr else el
            size = get_size(folder_structure, full_path)

            if size == -1:
                stack.append(full_path)
            else:
                heapq.heappush(maxheap, (-size, full_path))

    for _ in range(min(10, len(maxheap))):
        print(heapq.heappop(maxheap))




recursive_solution("")
print()
iterative_solution_with_queue("")
print()
iterative_solution_with_stack("")