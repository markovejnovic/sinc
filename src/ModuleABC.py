"""This file defines the ABC for making modules."""

from abc import ABC, abstractmethod
import typing

class ModuleABC(ABC):
    @abstractmethod
    def getPackageType() -> PackageType:
        """
        Returns the package type this module processes.

        This method is called upon module instantiation.
        """
        pass
